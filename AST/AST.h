#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <ctype.h>

typedef struct AST AST;

typedef struct AST {
    enum {
        AST_FUNCTION_CALL,
        AST_VAR_DEF,
        AST_VAR,
        AST_STRING,
    } type;

    /* Variable definition */
    char* var_def_name;
    AST* var_def_val;

    /* Var */
    char* var_name;
    
    /* function call */
    char* function_call_name;
    AST** function_call_args;
    size_t function_call_args_size;

    /* string */
    char* str_val;
} AST;

AST* init_ast(int type);

#endif
