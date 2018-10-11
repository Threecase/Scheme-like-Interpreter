/*
 * LISP Errors
 *
 */

#ifndef __ERROR_H
#define __ERROR_H


/* Errcode:
 *  Error types
 */
typedef enum Errcode
{   EC_UNBOUND_VAR,
    EC_BAD_SYNTAX,
    EC_INVALID_ARG,
    EC_GENERAL,
} Errcode;


/* Error:
 *  Exeptions
 */
typedef struct Error
{   Errcode errcode;
    char *flavour;
} Error;



char const *err_msg (Error e);
Error mkerr (Errcode t, char *flavour, ...);
struct Var mkerr_var (Errcode t, char *flavour, ...);

#endif
