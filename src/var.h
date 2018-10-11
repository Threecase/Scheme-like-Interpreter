/*
 * Variables
 *
 */

#ifndef __VAR_H
#define __VAR_H


/* Var:
 *  A LISP variable
 */
typedef struct Var
{   union
    {   Error    err;
        double   number;
        String   str;
        _Function fn;
        List     list;
    };
    enum
    {   VAR_ERROR,
        VAR_NUMBER,
        VAR_STRING,
        VAR_FUNCTION,
        VAR_LIST,
    } type;
} Var;



void free_var (Var v);


#endif

