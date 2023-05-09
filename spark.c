#include <stdio.h>
#include <stdlib.h>

#include "Lexer/lexer.h"
#include "Parser/parser.h"

int main() 
{
    TokenInfo* tokens = tokenize();
    Parser* parser = init_parser(tokens);
    AST* ast = parse(parser);

    ast_print(ast);
    free(tokens);
    ast_free(ast);
    return 0;
}
