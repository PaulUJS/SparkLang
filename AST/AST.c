#include "AST.h"

AST* init_ast(int type)
{
    AST* ast = malloc(sizeof(AST));
    ast->type = type;

    /* Variable definition */
    ast->var_def_name = (void*) 0;
    ast->var_def_val = (void*) 0;

    /* Var */
    ast->var_name = (void*) 0;
    
    /* function call */
    ast->function_call_name = (void*) 0;
    ast->function_call_args = (void*) 0;
    ast->function_call_args_size = (void*) 0;

    /* string */
    ast->str_val = (void*) 0;
    return ast;
}
