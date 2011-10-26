#
# (C) Tenable Network Security
#

if ( ! defined_func("bn_random") ) exit(0);
if(description)
{
 script_id(17508);
 script_version ("$Revision: 1.3 $");

 name["english"] = "HP-UX Security patch : PHSS_29891";
 
 script_name(english:name["english"]);
 
 desc["english"] = '
The remote host is missing HP-UX Security Patch number PHSS_29891 .
(SSRT3622 rev.3 HP-UX Apache HTTP Server Denial of Service, unauthorized access.)

Solution : ftp://ftp.itrc.hp.com/superseded_patches/hp-ux_patches/s700_800/11.X/PHSS_29891
See also : HPUX security bulletin 284
Risk factor : High';

 script_description(english:desc["english"]);
 
 summary["english"] = "Checks for patch PHSS_29891";
 script_summary(english:summary["english"]);
 
 script_category(ACT_GATHER_INFO);
 
 script_copyright(english:"This script is Copyright (C) 2006 Tenable Network Security");
 family["english"] = "HP-UX Local Security Checks";
 script_family(english:family["english"]);
 
 script_dependencies("ssh_get_info.nasl");
 script_require_keys("Host/HP-UX/swlist");
 exit(0);
}

include("hpux.inc");

if ( ! hpux_check_ctx ( ctx:"800:11.04 700:11.04 " ) )
{
 exit(0);
}

if ( hpux_patch_installed (patches:"PHSS_29891 PHSS_30646 PHSS_34165 PHSS_35480 ") )
{
 exit(0);
}

if ( hpux_check_patch( app:"VaultTGP.TGP-CORE", version:"A.04.60") )
{
 security_hole(0);
 exit(0);
}
