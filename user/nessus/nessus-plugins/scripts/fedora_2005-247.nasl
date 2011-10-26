#
# (C) Tenable Network Security
#
# This plugin text is was extracted from the Fedora Security Advisory
#


if ( ! defined_func("bn_random") ) exit(0);
if(description)
{
 script_id(19633);
 script_version ("$Revision: 1.2 $");
 script_cve_id("CVE-2005-0255", "CVE-2005-0399");
 
 name["english"] = "Fedora Core 3 2005-247: thunderbird";
 
 script_name(english:name["english"]);
 
 desc["english"] = "
The remote host is missing the patch for the advisory FEDORA-2005-247 (thunderbird).

Mozilla Thunderbird is a standalone mail and newsgroup client.

Update Information:

A buffer overflow bug was found in the way Thunderbird processes GIF
images. It is possible for an attacker to create a specially crafted
GIF image, which when viewed by a victim will execute arbitrary code
as the victim. The Common Vulnerabilities and Exposures project
(cve.mitre.org) has assigned the name CVE-2005-0399 to this issue.
A bug was found in the Thunderbird string handling functions. If a
malicious website is able to exhaust a system's memory, it becomes
possible to execute arbitrary code. The Common Vulnerabilities and
Exposures project (cve.mitre.org) has assigned the name CVE-2005-0255
to this issue.
Users of Thunderbird are advised to upgrade to this updated package
which contains Thunderbird version 1.0.2 and is not vulnerable to
these issues.
This update enables pango rendering by default.


Solution : Get the newest Fedora Updates
Risk factor : High";



 script_description(english:desc["english"]);
 
 summary["english"] = "Check for the version of the thunderbird package";
 script_summary(english:summary["english"]);
 
 script_category(ACT_GATHER_INFO);
 
 script_copyright(english:"This script is Copyright (C) 2005 Tenable Network Security");
 family["english"] = "Fedora Local Security Checks";
 script_family(english:family["english"]);
 
 script_dependencies("ssh_get_info.nasl");
 script_require_keys("Host/RedHat/rpm-list");
 exit(0);
}

include("rpm.inc");
if ( rpm_check( reference:"thunderbird-1.0.2-1.3.1", release:"FC3") )
{
 security_hole(0);
 exit(0);
}
if ( rpm_check( reference:"thunderbird-debuginfo-1.0.2-1.3.1", release:"FC3") )
{
 security_hole(0);
 exit(0);
}
if ( rpm_exists(rpm:"thunderbird-", release:"FC3") )
{
 set_kb_item(name:"CVE-2005-0255", value:TRUE);
 set_kb_item(name:"CVE-2005-0399", value:TRUE);
}
