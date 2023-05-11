#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <stddef.h>

#include "../Lexer/lexer.h"
#include "../AST/AST.h"

typedef struct Parser {
    TokenInfo* tokens;
    size_t index;
} Parser;

Parser* init_parser(TokenInfo* tokens);
AST* parse(Parser* parser);

AST* expression(Parser* parser);
AST* equality(Parser* parser);
AST* comparison(Parser* parser);
AST* add(Parser* parser);
AST* subtract(Parser* parser);
AST* multiply(Parser* parser);
AST* divide(Parser* parser);
AST* unary(Parser* parser);
AST* primary(Parser* parser);

bool match_tokens(Parser* parser, Token token);
bool at_end(Parser* parser);
bool check(Parser* parser, Token token);

TokenInfo previous(Parser* parser);
TokenInfo advance(Parser* parser);
TokenInfo peek(Parser* parser);

int num_match(NumLiteral num);

#endif
