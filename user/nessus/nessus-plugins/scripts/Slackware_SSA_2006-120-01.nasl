# This script was automatically generated from the SSA-2006-120-01
# Slackware Security Advisory
# It is released under the Nessus Script Licence.
# Slackware Security Advisories are copyright 1999-2004 Slackware Linux, Inc.
# SSA2nasl Convertor is copyright 2004 Michel Arboi
# See http://www.slackware.com/about/ or http://www.slackware.com/security/
# Slackware(R) is a registered trademark of Slackware Linux, Inc.

if (! defined_func("bn_random")) exit(0);
desc='
New Thunderbird packages are available for Slackware 10.2
and -current to fix security issues.

More details about the issues may be found here:

  http://www.mozilla.org/projects/security/known-vulnerabilities.html#thunderbird


';
if (description) {
script_id(21314);
script_version("$Revision: 1.1 $");
script_category(ACT_GATHER_INFO);
script_family(english: "Slackware Local Security Checks");
script_dependencies("ssh_get_info.nasl");
script_copyright("This script is Copyright (C) 2006 Michel Arboi <mikhail@nessus.org>");
script_require_keys("Host/Slackware/release", "Host/Slackware/packages");
script_description(english: desc);

script_xref(name: "SSA", value: "2006-120-01");
script_summary("SSA-2006-120-01 thunderbird ");
name["english"] = "SSA-2006-120-01 thunderbird ";
script_name(english:name["english"]);
exit(0);
}

include('slackware.inc');
include('global_settings.inc');

if (slackware_check(osver: "10.2", pkgname: "mozilla-thunderbird", pkgver: "1.5.0.2", pkgnum:  "1", pkgarch: "i686")) {
w++;
if (report_verbosity > 0) desc = strcat(desc, '
The package mozilla-thunderbird is vulnerable in Slackware 10.2
Upgrade to mozilla-thunderbird-1.5.0.2-i686-1 or newer.
');
}
if (slackware_check(osver: "-current", pkgname: "mozilla-thunderbird", pkgver: "1.5.0.2", pkgnum:  "1", pkgarch: "i686")) {
w++;
if (report_verbosity > 0) desc = strcat(desc, '
The package mozilla-thunderbird is vulnerable in Slackware -current
Upgrade to mozilla-thunderbird-1.5.0.2-i686-1 or newer.
');
}

if (w) { security_hole(port: 0, data: desc); }
