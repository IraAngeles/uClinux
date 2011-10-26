#
# (C) Tenable Network Security
#
#
# The text of this plugin is (C) Red Hat Inc.

if ( ! defined_func("bn_random") ) exit(0);
if(description)
{
 script_id(20238);
 script_version ("$Revision: 1.1 $");
 script_cve_id("CVE-2005-2975", "CVE-2005-3186");

 name["english"] = "RHSA-2005-811: gtk";
 
 script_name(english:name["english"]);
 
 desc["english"] = '

  Updated gtk2 packages that fix two security issues are now available.

  This update has been rated as having important security impact by the Red
  Hat Security Response Team.

  The gtk2 package contains the GIMP ToolKit (GTK+), a library for creating
  graphical user interfaces for the X Window System.

  A bug was found in the way gtk2 processes XPM images. An attacker could
  create a carefully crafted XPM file in such a way that it could cause an
  application linked with gtk2 to execute arbitrary code when the file was
  opened by a victim. The Common Vulnerabilities and Exposures project has
  assigned the name CVE-2005-3186 to this issue.

  Ludwig Nussel discovered an infinite-loop denial of service bug in the way
  gtk2 processes XPM images. An attacker could create a carefully crafted XPM
  file in such a way that it could cause an application linked with gtk2 to
  stop responding when the file was opened by a victim. The Common
  Vulnerabilities and Exposures project has assigned the name CVE-2005-2975
  to this issue.

  Users of gtk2 are advised to upgrade to these updated packages, which
  contain backported patches and are not vulnerable to these issues.




Solution : http://rhn.redhat.com/errata/RHSA-2005-811.html
Risk factor : High';

 script_description(english:desc["english"]);
 
 summary["english"] = "Check for the version of the gtk packages";
 script_summary(english:summary["english"]);
 
 script_category(ACT_GATHER_INFO);
 
 script_copyright(english:"This script is Copyright (C) 2005 Tenable Network Security");
 family["english"] = "Red Hat Local Security Checks";
 script_family(english:family["english"]);
 
 script_dependencies("ssh_get_info.nasl");
 
 script_require_keys("Host/RedHat/rpm-list");
 exit(0);
}

include("rpm.inc");
if ( rpm_check( reference:"gtk2-2.2.4-19", release:"RHEL3") )
{
 security_hole(0);
 exit(0);
}
if ( rpm_check( reference:"gtk2-devel-2.2.4-19", release:"RHEL3") )
{
 security_hole(0);
 exit(0);
}
if ( rpm_check( reference:"gtk2-2.4.13-18", release:"RHEL4") )
{
 security_hole(0);
 exit(0);
}
if ( rpm_check( reference:"gtk2-devel-2.4.13-18", release:"RHEL4") )
{
 security_hole(0);
 exit(0);
}

if ( rpm_exists(rpm:"gtk-", release:"RHEL3") )
{
 set_kb_item(name:"CVE-2005-2975", value:TRUE);
 set_kb_item(name:"CVE-2005-3186", value:TRUE);
}
if ( rpm_exists(rpm:"gtk-", release:"RHEL4") )
{
 set_kb_item(name:"CVE-2005-2975", value:TRUE);
 set_kb_item(name:"CVE-2005-3186", value:TRUE);
}

set_kb_item(name:"RHSA-2005-811", value:TRUE);
