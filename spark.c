#include <stdio.h>
#include <stdlib.h>

#include "Lexer/lexer.h"
#include "Parser/parser.h"
#include "AST/AST.h"

void emit(TokenInfo* tokens)
{
    AST *term = 
    AST_NEW(AST_ADD,
      AST_NEW(AST_NUMBER, 4),
      AST_NEW(AST_ADD,
        AST_NEW(AST_MUL, 
          AST_NEW(AST_NUMBER, 2), 
          AST_NEW(AST_NUMBER, 10),
        ),
        AST_NEW(AST_MUL,
          AST_NEW(AST_NUMBER, 3),
          AST_NEW(AST_ADD,
            AST_NEW(AST_NUMBER, 5),
            AST_NEW(AST_NUMBER, 1),
          ),
        ),
      ),
    );
    ast_print(term);
    free(tokens);
    ast_free(term);
}

int main() 
{
    TokenInfo* tokens = tokenize();
    Parser* parser = init_parser(tokens);
    AST* ast = parse(parser);
    ast_print(ast);
    free(tokens);
    ast_free(ast);
    //emit(tokens);
    return 0;
}
