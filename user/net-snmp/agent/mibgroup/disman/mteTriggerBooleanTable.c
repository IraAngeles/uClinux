/*
 * This file was generated by mib2c and is intended for use as
 * a mib module for the ucd-snmp snmpd agent. 
 */


/*
 * This should always be included first before anything else 
 */
#include <net-snmp/net-snmp-config.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif
#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif


/*
 * minimal include directives 
 */
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include "header_complex.h"
#include "mteTriggerBooleanTable.h"
#include "mteTriggerTable.h"


/*
 * mteTriggerBooleanTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */


oid             mteTriggerBooleanTable_variables_oid[] =
    { 1, 3, 6, 1, 2, 1, 88, 1, 2, 5 };


/*
 * variable2 mteTriggerBooleanTable_variables:
 *   this variable defines function callbacks and type return information 
 *   for the mteTriggerBooleanTable mib section 
 */


struct variable2 mteTriggerBooleanTable_variables[] = {
    /*
     * magic number        , variable type , ro/rw , callback fn  , L, oidsuffix 
     */
#define   MTETRIGGERBOOLEANCOMPARISON  3
    {MTETRIGGERBOOLEANCOMPARISON, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 1}},
#define   MTETRIGGERBOOLEANVALUE  4
    {MTETRIGGERBOOLEANVALUE, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 2}},
#define   MTETRIGGERBOOLEANSTARTUP  5
    {MTETRIGGERBOOLEANSTARTUP, ASN_INTEGER, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 3}},
#define   MTETRIGGERBOOLEANOBJECTSOWNER  6
    {MTETRIGGERBOOLEANOBJECTSOWNER, ASN_OCTET_STR, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 4}},
#define   MTETRIGGERBOOLEANOBJECTS  7
    {MTETRIGGERBOOLEANOBJECTS, ASN_OCTET_STR, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 5}},
#define   MTETRIGGERBOOLEANEVENTOWNER  8
    {MTETRIGGERBOOLEANEVENTOWNER, ASN_OCTET_STR, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 6}},
#define   MTETRIGGERBOOLEANEVENT  9
    {MTETRIGGERBOOLEANEVENT, ASN_OCTET_STR, NETSNMP_OLDAPI_RWRITE,
     var_mteTriggerBooleanTable, 2, {1, 7}},

};
/*
 * (L = length of the oidsuffix) 
 */


/*
 * global storage of our data, saved in and configured by header_complex() 
 */
extern struct header_complex_index *mteTriggerTableStorage;


/*
 * init_mteTriggerBooleanTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void
init_mteTriggerBooleanTable(void)
{
    DEBUGMSGTL(("mteTriggerBooleanTable", "initializing...  "));


    /*
     * register ourselves with the agent to handle our mib tree 
     */
    REGISTER_MIB("mteTriggerBooleanTable",
                 mteTriggerBooleanTable_variables, variable2,
                 mteTriggerBooleanTable_variables_oid);

    DEBUGMSGTL(("mteTriggerBooleanTable", "done.\n"));
}

/*
 * var_mteTriggerBooleanTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_mteTriggerBooleanTable above.
 */
unsigned char  *
var_mteTriggerBooleanTable(struct variable *vp,
                           oid * name,
                           size_t * length,
                           int exact,
                           size_t * var_len, WriteMethod ** write_method)
{


    struct mteTriggerTable_data *StorageTmp = NULL;


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "var_mteTriggerBooleanTable: Entering...  \n"));
    /*
     * this assumes you have registered all your data properly
     */
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, vp, name, length, exact,
                        var_len, write_method)) == NULL)
        return NULL;

    if (!(StorageTmp->mteTriggerTest[0] & MTETRIGGERTEST_BOOLEAN))
        return NULL;

    /*
     * this is where we do the value assignments for the mib results.
     */
    switch (vp->magic) {


    case MTETRIGGERBOOLEANCOMPARISON:
        *write_method = write_mteTriggerBooleanComparison;
        *var_len = sizeof(StorageTmp->mteTriggerBooleanComparison);
        return (u_char *) & StorageTmp->mteTriggerBooleanComparison;

    case MTETRIGGERBOOLEANVALUE:
        *write_method = write_mteTriggerBooleanValue;
        *var_len = sizeof(StorageTmp->mteTriggerBooleanValue);
        return (u_char *) & StorageTmp->mteTriggerBooleanValue;

    case MTETRIGGERBOOLEANSTARTUP:
        *write_method = write_mteTriggerBooleanStartup;
        *var_len = sizeof(StorageTmp->mteTriggerBooleanStartup);
        return (u_char *) & StorageTmp->mteTriggerBooleanStartup;

    case MTETRIGGERBOOLEANOBJECTSOWNER:
        *write_method = write_mteTriggerBooleanObjectsOwner;
        *var_len = StorageTmp->mteTriggerBooleanObjectsOwnerLen;
        return (u_char *) StorageTmp->mteTriggerBooleanObjectsOwner;

    case MTETRIGGERBOOLEANOBJECTS:
        *write_method = write_mteTriggerBooleanObjects;
        *var_len = StorageTmp->mteTriggerBooleanObjectsLen;
        return (u_char *) StorageTmp->mteTriggerBooleanObjects;

    case MTETRIGGERBOOLEANEVENTOWNER:
        *write_method = write_mteTriggerBooleanEventOwner;
        *var_len = StorageTmp->mteTriggerBooleanEventOwnerLen;
        return (u_char *) StorageTmp->mteTriggerBooleanEventOwner;

    case MTETRIGGERBOOLEANEVENT:
        *write_method = write_mteTriggerBooleanEvent;
        *var_len = StorageTmp->mteTriggerBooleanEventLen;
        return (u_char *) StorageTmp->mteTriggerBooleanEvent;


    default:
        ERROR_MSG("");
    }
    return NULL;
}




int
write_mteTriggerBooleanComparison(int action,
                                  u_char * var_val,
                                  u_char var_val_type,
                                  size_t var_val_len,
                                  u_char * statP,
                                  oid * name, size_t name_len)
{
    static int      tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanComparison entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER) {
            fprintf(stderr,
                    "write to mteTriggerBooleanComparison not ASN_INTEGER\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in long_ret for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanComparison;
        StorageTmp->mteTriggerBooleanComparison = *((long *) var_val);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        StorageTmp->mteTriggerBooleanComparison = tmpvar;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */

        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanValue(int action,
                             u_char * var_val,
                             u_char var_val_type,
                             size_t var_val_len,
                             u_char * statP, oid * name, size_t name_len)
{
    static int      tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanValue entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER) {
            fprintf(stderr,
                    "write to mteTriggerBooleanValue not ASN_INTEGER\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in long_ret for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanValue;
        StorageTmp->mteTriggerBooleanValue = *((long *) var_val);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        StorageTmp->mteTriggerBooleanValue = tmpvar;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */

        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanStartup(int action,
                               u_char * var_val,
                               u_char var_val_type,
                               size_t var_val_len,
                               u_char * statP, oid * name, size_t name_len)
{
    static int      tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanStartup entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_INTEGER) {
            fprintf(stderr,
                    "write to mteTriggerBooleanStartup not ASN_INTEGER\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in long_ret for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanStartup;
        StorageTmp->mteTriggerBooleanStartup = *((long *) var_val);
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        StorageTmp->mteTriggerBooleanStartup = tmpvar;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */

        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanObjectsOwner(int action,
                                    u_char * var_val,
                                    u_char var_val_type,
                                    size_t var_val_len,
                                    u_char * statP,
                                    oid * name, size_t name_len)
{
    static char    *tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanObjectsOwner entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OCTET_STR) {
            fprintf(stderr,
                    "write to mteTriggerBooleanObjectsOwner not ASN_OCTET_STR\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in string for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanObjectsOwner;
        tmplen = StorageTmp->mteTriggerBooleanObjectsOwnerLen;
        StorageTmp->mteTriggerBooleanObjectsOwner =
            netsnmp_strdup_and_null(var_val, var_val_len);
        StorageTmp->mteTriggerBooleanObjectsOwnerLen = var_val_len;
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->mteTriggerBooleanObjectsOwner);
        StorageTmp->mteTriggerBooleanObjectsOwner = tmpvar;
        StorageTmp->mteTriggerBooleanObjectsOwnerLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);
        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanObjects(int action,
                               u_char * var_val,
                               u_char var_val_type,
                               size_t var_val_len,
                               u_char * statP, oid * name, size_t name_len)
{
    static char    *tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanObjects entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OCTET_STR) {
            fprintf(stderr,
                    "write to mteTriggerBooleanObjects not ASN_OCTET_STR\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in string for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanObjects;
        tmplen = StorageTmp->mteTriggerBooleanObjectsLen;
        StorageTmp->mteTriggerBooleanObjects =
            netsnmp_strdup_and_null(var_val, var_val_len);
        StorageTmp->mteTriggerBooleanObjectsLen = var_val_len;
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->mteTriggerBooleanObjects);
        StorageTmp->mteTriggerBooleanObjects = tmpvar;
        StorageTmp->mteTriggerBooleanObjectsLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);
        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanEventOwner(int action,
                                  u_char * var_val,
                                  u_char var_val_type,
                                  size_t var_val_len,
                                  u_char * statP,
                                  oid * name, size_t name_len)
{
    static char    *tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanEventOwner entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OCTET_STR) {
            fprintf(stderr,
                    "write to mteTriggerBooleanEventOwner not ASN_OCTET_STR\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in string for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanEventOwner;
        tmplen = StorageTmp->mteTriggerBooleanEventOwnerLen;
        StorageTmp->mteTriggerBooleanEventOwner =
            netsnmp_strdup_and_null(var_val, var_val_len);
        StorageTmp->mteTriggerBooleanEventOwnerLen = var_val_len;
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->mteTriggerBooleanEventOwner);
        StorageTmp->mteTriggerBooleanEventOwner = tmpvar;
        StorageTmp->mteTriggerBooleanEventOwnerLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);
        break;
    }
    return SNMP_ERR_NOERROR;
}



int
write_mteTriggerBooleanEvent(int action,
                             u_char * var_val,
                             u_char var_val_type,
                             size_t var_val_len,
                             u_char * statP, oid * name, size_t name_len)
{
    static char    *tmpvar;
    struct mteTriggerTable_data *StorageTmp = NULL;
    static size_t   tmplen;
    size_t          newlen =
        name_len -
        (sizeof(mteTriggerBooleanTable_variables_oid) / sizeof(oid) + 3 -
         1);


    DEBUGMSGTL(("mteTriggerBooleanTable",
                "write_mteTriggerBooleanEvent entering action=%d...  \n",
                action));
    if ((StorageTmp =
         header_complex(mteTriggerTableStorage, NULL,
                        &name[sizeof(mteTriggerBooleanTable_variables_oid)
                              / sizeof(oid) + 3 - 1], &newlen, 1, NULL,
                        NULL)) == NULL)
        return SNMP_ERR_NOSUCHNAME;     /* remove if you support creation here */


    switch (action) {
    case RESERVE1:
        if (var_val_type != ASN_OCTET_STR) {
            fprintf(stderr,
                    "write to mteTriggerBooleanEvent not ASN_OCTET_STR\n");
            return SNMP_ERR_WRONGTYPE;
        }
        if (StorageTmp->storageType != ST_NONVOLATILE)
            return SNMP_ERR_NOTWRITABLE;
        break;


    case RESERVE2:
        /*
         * memory reseveration, final preparation... 
         */
        break;


    case FREE:
        /*
         * Release any resources that have been allocated 
         */
        break;


    case ACTION:
        /*
         * The variable has been stored in string for
         * you to use, and you have just been asked to do something with
         * it.  Note that anything done here must be reversable in the UNDO case 
         */
        tmpvar = StorageTmp->mteTriggerBooleanEvent;
        tmplen = StorageTmp->mteTriggerBooleanEventLen;
        StorageTmp->mteTriggerBooleanEvent =
            netsnmp_strdup_and_null(var_val, var_val_len);
        StorageTmp->mteTriggerBooleanEventLen = var_val_len;
        break;


    case UNDO:
        /*
         * Back out any changes made in the ACTION case 
         */
        SNMP_FREE(StorageTmp->mteTriggerBooleanEvent);
        StorageTmp->mteTriggerBooleanEvent = tmpvar;
        StorageTmp->mteTriggerBooleanEventLen = tmplen;
        break;


    case COMMIT:
        /*
         * Things are working well, so it's now safe to make the change
         * permanently.  Make sure that anything done here can't fail! 
         */
        SNMP_FREE(tmpvar);
        break;
    }
    return SNMP_ERR_NOERROR;
}
