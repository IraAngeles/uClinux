# This script was automatically generated from the dsa-1005
# Debian Security Advisory
# It is released under the Nessus Script Licence.
# Advisory is copyright 1997-2004 Software in the Public Interest, Inc.
# See http://www.debian.org/license
# DSA2nasl Convertor is copyright 2004 Michel Arboi

if (! defined_func('bn_random')) exit(0);

desc = '
Simon Kilvington discovered that specially crafted PNG images can trigger
a heap overflow in libavcodec, the multimedia library of ffmpeg, which may
lead to the execution of arbitrary code.
xine-lib includes a local copy of libavcodec.
The old stable distribution (woody) isn\'t affected by this problem.
For the stable distribution (sarge) this problem has been fixed in
version 1.0.1-1sarge2.
For the unstable distribution (sid) this problem has been fixed in
version 1.0.1-1.5.
We recommend that you upgrade your xine-lib package.


Solution : http://www.debian.org/security/2006/dsa-1005
Risk factor : High';

if (description) {
 script_id(22547);
 script_version("$Revision: 1.1 $");
 script_xref(name: "DSA", value: "1005");
 script_cve_id("CVE-2005-4048");

 script_description(english: desc);
 script_copyright(english: "This script is (C) 2006 Michel Arboi <mikhail@nessus.org>");
 script_name(english: "[DSA1005] DSA-1005-1 xine-lib");
 script_category(ACT_GATHER_INFO);
 script_family(english: "Debian Local Security Checks");
 script_dependencies("ssh_get_info.nasl");
 script_require_keys("Host/Debian/dpkg-l");
 script_summary(english: "DSA-1005-1 xine-lib");
 exit(0);
}

include("debian_package.inc");

w = 0;
if (deb_check(prefix: 'xine-lib', release: '', reference: '1.0.1-1.5')) {
 w ++;
 if (report_verbosity > 0) desc = strcat(desc, '\nThe package xine-lib is vulnerable in Debian .\nUpgrade to xine-lib_1.0.1-1.5\n');
}
if (deb_check(prefix: 'libxine-dev', release: '3.1', reference: '1.0.1-1sarge2')) {
 w ++;
 if (report_verbosity > 0) desc = strcat(desc, '\nThe package libxine-dev is vulnerable in Debian 3.1.\nUpgrade to libxine-dev_1.0.1-1sarge2\n');
}
if (deb_check(prefix: 'libxine1', release: '3.1', reference: '1.0.1-1sarge2')) {
 w ++;
 if (report_verbosity > 0) desc = strcat(desc, '\nThe package libxine1 is vulnerable in Debian 3.1.\nUpgrade to libxine1_1.0.1-1sarge2\n');
}
if (deb_check(prefix: 'xine-lib', release: '3.1', reference: '1.0.1-1sarge2')) {
 w ++;
 if (report_verbosity > 0) desc = strcat(desc, '\nThe package xine-lib is vulnerable in Debian sarge.\nUpgrade to xine-lib_1.0.1-1sarge2\n');
}
if (w) { security_hole(port: 0, data: desc); }
