# This script was automatically generated from 
#  http://www.gentoo.org/security/en/glsa/glsa-200609-17.xml
# It is released under the Nessus Script Licence.
# The messages are release under the Creative Commons - Attribution /
# Share Alike license. See http://creativecommons.org/licenses/by-sa/2.0/
#
# Avisory is copyright 2001-2006 Gentoo Foundation, Inc.
# GLSA2nasl Convertor is copyright 2004 Michel Arboi <mikhail@nessus.org>

if (! defined_func('bn_random')) exit(0);

if (description)
{
 script_id(22464);
 script_version("$Revision: 1.1 $");
 script_xref(name: "GLSA", value: "200609-17");
 script_cve_id("CVE-2006-4924");

 desc = 'The remote host is affected by the vulnerability described in GLSA-200609-17
(OpenSSH: Denial of Service)


    Tavis Ormandy of the Google Security Team discovered a Denial of
    Service vulnerability in the SSH protocol version 1 CRC compensation
    attack detector.
  
Impact

    A remote unauthenticated attacker may be able to trigger excessive CPU
    usage by sending a pathological SSH message, denying service to other
    legitimate users or processes.
  
Workaround

    The system administrator may disable SSH protocol version 1 in
    /etc/ssh/sshd_config.
  
References:
    http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2006-4924


Solution: 
    All OpenSSH users should upgrade to the latest version:
    # emerge --sync
    # emerge --ask --oneshot --verbose ">=net-misc/openssh-4.3_p2-r5"
  

Risk factor : Medium
';
 script_description(english: desc);
 script_copyright(english: "(C) 2006 Michel Arboi <mikhail@nessus.org>");
 script_name(english: "[GLSA-200609-17] OpenSSH: Denial of Service");
 script_category(ACT_GATHER_INFO);
 script_family(english: "Gentoo Local Security Checks");
 script_dependencies("ssh_get_info.nasl");
 script_require_keys('Host/Gentoo/qpkg-list');
 script_summary(english: 'OpenSSH: Denial of Service');
 exit(0);
}

include('qpkg.inc');
if (qpkg_check(package: "net-misc/openssh", unaffected: make_list("ge 4.3_p2-r5"), vulnerable: make_list("lt 4.3_p2-r5")
)) { security_warning(0); exit(0); }
