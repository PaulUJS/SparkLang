#include <stdio.h>
#include <stdlib.h>

#include "Lexer/lexer.h"
#include "Parser/parser.h"

int main() 
{
    TokenInfo* tokens = tokenize();
    free(tokens);
    return 0;
}
