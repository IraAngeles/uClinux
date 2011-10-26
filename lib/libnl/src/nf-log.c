/*
 * src/nf-log.c     Monitor netfilter log events
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation version 2.1
 *	of the License.
 *
 * Copyright (c) 2003-2006 Thomas Graf <tgraf@suug.ch>
 * Copyright (c) 2007 Philip Craig <philipc@snapgear.com>
 * Copyright (c) 2007 Secure Computing Corporation
 */

#include <sys/types.h>
#include <linux/netfilter/nfnetlink_log.h>

#include "utils.h"
#include <netlink/netfilter/nfnl.h>
#include <netlink/netfilter/log.h>

static void obj_input(struct nl_object *obj, void *arg)
{
	struct nl_dump_params dp = {
		.dp_type = NL_DUMP_STATS,
		.dp_fd = stdout,
		.dp_dump_msgtype = 1,
	};

	nl_object_dump(obj, &dp);
}

static int event_input(struct nl_msg *msg, void *arg)
{
	if (nl_msg_parse(msg, &obj_input, NULL) < 0)
		fprintf(stderr, "<<EVENT>> Unknown message type\n");

	/* Exit nl_recvmsgs_def() and return to the main select() */
	return NL_STOP;
}

int main(int argc, char *argv[])
{
	struct nl_handle *nfnlh;
	struct nl_handle *rtnlh;
        struct nl_cache *link_cache;
	struct nfnl_log *log;
	enum nfnl_log_copy_mode copy_mode;
	uint32_t copy_range;
	int err = 1;
	int family;

	if (nltool_init(argc, argv) < 0)
		return -1;

	nfnlh = nltool_alloc_handle();
	if (nfnlh == NULL)
		return -1;

	nl_disable_sequence_check(nfnlh);

	nl_socket_modify_cb(nfnlh, NL_CB_VALID, NL_CB_CUSTOM, event_input, NULL);

	if ((argc > 1 && !strcasecmp(argv[1], "-h")) || argc < 3) {
		printf("Usage: nf-log family group [ copy_mode ] "
		       "[copy_range] \n");
		return 2;
	}

	if (nfnl_connect(nfnlh) < 0) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout;
	}

	family = nl_str2af(argv[1]);
	if (family == AF_UNSPEC) {
		fprintf(stderr, "Unknown family: %s\n", argv[1]);
		goto errout;
	}

	nfnl_log_pf_unbind(nfnlh, family);
	if (nfnl_log_pf_bind(nfnlh, family) < 0) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout;
	}

	log = nfnl_log_alloc();
	if (log == NULL) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout;
	}

	nfnl_log_set_group(log, atoi(argv[2]));

	copy_mode = NFNL_LOG_COPY_META;
	if (argc > 3) {
		copy_mode = nfnl_log_str2copy_mode(argv[3]);
		if (copy_mode < 0) {
			fprintf(stderr, "%s\n", nl_geterror());
			goto errout;
		}
	}
	nfnl_log_set_copy_mode(log, copy_mode);

	copy_range = 0xFFFF;
	if (argc > 4)
		copy_mode = atoi(argv[4]);
	nfnl_log_set_copy_range(log, copy_range);

	if (nfnl_log_create(nfnlh, log) <0) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout;
	}

	{
		struct nl_dump_params dp = {
			.dp_type = NL_DUMP_STATS,
			.dp_fd = stdout,
			.dp_dump_msgtype = 1,
		};

		printf("log params: ");
		nl_object_dump((struct nl_object *) log, &dp);
	}

	rtnlh = nltool_alloc_handle();
	if (rtnlh == NULL) {
		goto errout_close;
	}

	if (nl_connect(rtnlh, NETLINK_ROUTE) < 0) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout;
	}

	if ((link_cache = rtnl_link_alloc_cache(rtnlh)) == NULL) {
		fprintf(stderr, "%s\n", nl_geterror());
		goto errout_close;
	}

	nl_cache_mngt_provide(link_cache);

	while (1) {
		fd_set rfds;
		int nffd, rtfd, maxfd, retval;

		FD_ZERO(&rfds);

		maxfd = nffd = nl_socket_get_fd(nfnlh);
		FD_SET(nffd, &rfds);

		rtfd = nl_socket_get_fd(rtnlh);
		FD_SET(rtfd, &rfds);
		if (maxfd < rtfd)
			maxfd = rtfd;

		/* wait for an incoming message on the netlink socket */
		retval = select(maxfd+1, &rfds, NULL, NULL, NULL);

		if (retval) {
			if (FD_ISSET(nffd, &rfds))
				nl_recvmsgs_default(nfnlh);
			if (FD_ISSET(rtfd, &rfds))
				nl_recvmsgs_default(rtnlh);
		}
	}

	nl_cache_mngt_unprovide(link_cache);
	nl_cache_free(link_cache);

	nfnl_log_put(log);

	nl_close(rtnlh);
	nl_handle_destroy(rtnlh);
errout_close:
	nl_close(nfnlh);
	nl_handle_destroy(nfnlh);
errout:
	return err;
}
