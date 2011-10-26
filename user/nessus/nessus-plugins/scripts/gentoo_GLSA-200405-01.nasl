# This script was automatically generated from 
#  http://www.gentoo.org/security/en/glsa/glsa-200405-01.xml
# It is released under the Nessus Script Licence.
# The messages are release under the Creative Commons - Attribution /
# Share Alike license. See http://creativecommons.org/licenses/by-sa/2.0/
#
# Avisory is copyright 2001-2005 Gentoo Foundation, Inc.
# GLSA2nasl Convertor is copyright 2004 Michel Arboi <mikhail@nessus.org>

if (! defined_func('bn_random')) exit(0);

if (description)
{
 script_id(14487);
 script_version("$Revision: 1.3 $");
 script_xref(name: "GLSA", value: "200405-01");
 script_cve_id("CVE-2004-0179");

 desc = 'The remote host is affected by the vulnerability described in GLSA-200405-01
(Multiple format string vulnerabilities in neon 0.24.4 and earlier)


    There are multiple format string vulnerabilities in libneon which may allow
    a malicious WebDAV server to execute arbitrary code under the context of
    the process using libneon.
  
Impact

    An attacker may be able to execute arbitrary code under the context of the
    process using libneon.
  
Workaround

    A workaround is not currently known for this issue. All users are advised
    to upgrade to the latest version of the affected package.
  
References:
    http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2004-0179


Solution: 
    Neon users should upgrade to version 0.24.5 or later:
    # emerge sync
    # emerge -pv ">=net-misc/neon-0.24.5"
    # emerge ">=net-misc/neon-0.24.5"
  

Risk factor : Medium
';
 script_description(english: desc);
 script_copyright(english: "(C) 2005 Michel Arboi <mikhail@nessus.org>");
 script_name(english: "[GLSA-200405-01] Multiple format string vulnerabilities in neon 0.24.4 and earlier");
 script_category(ACT_GATHER_INFO);
 script_family(english: "Gentoo Local Security Checks");
 script_dependencies("ssh_get_info.nasl");
 script_require_keys('Host/Gentoo/qpkg-list');
 script_summary(english: 'Multiple format string vulnerabilities in neon 0.24.4 and earlier');
 exit(0);
}

include('qpkg.inc');
if (qpkg_check(package: "net-misc/neon", unaffected: make_list("ge 0.24.5"), vulnerable: make_list("le 0.24.4")
)) { security_warning(0); exit(0); }
