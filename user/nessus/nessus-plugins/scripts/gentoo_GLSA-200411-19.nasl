# This script was automatically generated from 
#  http://www.gentoo.org/security/en/glsa/glsa-200411-19.xml
# It is released under the Nessus Script Licence.
# The messages are release under the Creative Commons - Attribution /
# Share Alike license. See http://creativecommons.org/licenses/by-sa/2.0/
#
# Avisory is copyright 2001-2005 Gentoo Foundation, Inc.
# GLSA2nasl Convertor is copyright 2004 Michel Arboi <mikhail@nessus.org>

if (! defined_func('bn_random')) exit(0);

if (description)
{
 script_id(15694);
 script_version("$Revision: 1.3 $");
 script_xref(name: "GLSA", value: "200411-19");
 script_cve_id("CVE-2004-0456");

 desc = 'The remote host is affected by the vulnerability described in GLSA-200411-19
(Pavuk: Multiple buffer overflows)


    Pavuk contains several buffer overflow vulnerabilities in the code handling digest authentication and HTTP header processing. This issue is similar to GLSA 200407-19, but contains more vulnerabilities.
  
Impact

    A remote attacker could cause a buffer overflow, leading to arbitrary code execution with the rights of the user running Pavuk.
  
Workaround

    There is no known workaround at this time.
  
References:
    http://www.gentoo.org/security/en/glsa/glsa-200407-19.xml
    http://secunia.com/advisories/13120/
    http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2004-0456


Solution: 
    All Pavuk users should upgrade to the latest version:
    # emerge --sync
    # emerge --ask --oneshot --verbose ">=net-misc/pavuk-0.9.31"
  

Risk factor : Medium
';
 script_description(english: desc);
 script_copyright(english: "(C) 2005 Michel Arboi <mikhail@nessus.org>");
 script_name(english: "[GLSA-200411-19] Pavuk: Multiple buffer overflows");
 script_category(ACT_GATHER_INFO);
 script_family(english: "Gentoo Local Security Checks");
 script_dependencies("ssh_get_info.nasl");
 script_require_keys('Host/Gentoo/qpkg-list');
 script_summary(english: 'Pavuk: Multiple buffer overflows');
 exit(0);
}

include('qpkg.inc');
if (qpkg_check(package: "net-misc/pavuk", unaffected: make_list("ge 0.9.31"), vulnerable: make_list("lt 0.9.31")
)) { security_warning(0); exit(0); }
