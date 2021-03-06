/*
 * Data defs
 *
 */

#ifndef __DATA_H
#define __DATA_H

#include "string.h"
#include "error.h"
#include "lexer.h"

#include <gc/gc.h>

#include <stdio.h>      /* fprintf */
#include <stddef.h>     /* size_t */
#include <stdlib.h>     /* EXIT_FAILURE */
#include <stdbool.h>    /* bool */


/* TODO: make this configurable */
#define DEBUG_FILE  stderr

/* NOTE: this is so GCC ignores the unknown format
 * errors caused by the custom `%v' format */
/* FIXME: this could cause some headaches... consider removing it if
 * neccessary */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat="
#pragma GCC diagnostic ignored "-Wformat-extra-args"

#define fatal(format, ...)  ({  fprintf (stderr, "Fatal: %s -- " format "\n", __func__, ##__VA_ARGS__); exit (EXIT_FAILURE);  })
#define error(format, ...)  ({  fprintf (stderr, "Error: %s -- " format "\n", __func__, ##__VA_ARGS__);   })

#ifdef _DEBUG_BUILD
#define debug(format, ...)  ({  fprintf (DEBUG_FILE, "%s: " format "\n", __func__, ##__VA_ARGS__);   })
#else
#define debug(format, ...)
#endif



/* Pair:
 *  Pair of Vars
 */
typedef struct Pair
{   struct Var *car,
               *cdr;
} Pair;


/* LISPFunction:
 *  A non-builtin function -- essentially
 *  just a saved token list
 */
typedef struct LISPFunction
{   struct Var *body;
    struct Var *env;
} LISPFunction;


/* BuiltIn:
 *  Builtins are is basically just
 *  C function pointers
 */
typedef struct BuiltIn
{   struct Var *(*fn)(struct Var *argv, struct Var *env);
    char const *name;
} BuiltIn;


/* Function:
 *  A Function can be either a
 *  LISPFunction or a BuiltIn
 *
 *  NOTE: named _Function because
 *  GNU Readline has a _PUBLIC_
 *  typedef for Function already
 *  ( v_v)
 */
typedef struct _Function
{   union
    {   LISPFunction fn;
        BuiltIn      builtin;
    };
    enum
    {   FN_LISPFN,
        FN_BUILTIN,
    } type;
} _Function;

_Function duplicate_fn (_Function f);


#include "var.h"


#endif

