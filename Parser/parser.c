#include "parser.h"
#include <stdio.h>

Parser* init_parser(TokenInfo* tokens)
{
    Parser* parser = malloc(sizeof(Parser*));
    parser->tokens = tokens;
    parser->index = 0;
    return parser;
}

AST* parse(Parser* parser)
{   
    AST* ast;
    while (!at_end(parser))
    {
        ast = expression(parser);
    }
    return ast;
}

AST* expression(Parser* parser)
{
    return add(parser);
}

AST* equality(Parser* parser)
{
}

AST* comparison(Parser* parser)
{
}

AST* add(Parser* parser)
{
    AST* ast = subtract(parser);
    while (match_tokens(parser, PLUS))
    {
        AST* right = subtract(parser);
        ast = AST_NEW(AST_ADD, right, ast);
    }
    return ast;
}

AST* subtract(Parser* parser)
{
    AST* ast = multiply(parser);
    while (match_tokens(parser, MINUS))
    {
        AST* right = multiply(parser);
        ast = AST_NEW(AST_SUB, right, ast);
    }
    return ast;

}

AST* multiply(Parser* parser)
{
    AST* ast = divide(parser);
    while (match_tokens(parser, STAR))
    {
        AST* right = divide(parser);
        ast = AST_NEW(AST_MUL, right, ast);
    }
    return ast;
}

AST* divide(Parser* parser)
{
    AST* ast = unary(parser);
    while (match_tokens(parser, SLASH))
    {
        AST* right = unary(parser);
        ast = AST_NEW(AST_DIV, right, ast);
    }
    return ast;
}

AST* unary(Parser* parser)
{
    return primary(parser);
}

AST* primary(Parser* parser)
{
    AST* ast;
    if (match_tokens(parser, NUMLITERAL))
    {
        TokenInfo num = previous(parser);
        ast = AST_NEW(AST_NUMBER, num.num);
    }
    return ast;
}

bool match_tokens(Parser* parser, Token token)
{
    if (check(parser, token))
    {
        advance(parser);
        return true;
    }
    return false;
}

bool check(Parser* parser, Token token)
{
    if (at_end(parser))
        return false;
    return peek(parser).token == token;
}

TokenInfo previous(Parser* parser)
{
    return parser->tokens[parser->index - 1];
}

TokenInfo advance(Parser* parser)
{
    if (!at_end(parser))
        parser->index += 1;
    return previous(parser);
}

bool at_end(Parser* parser)
{
    return parser->tokens[parser->index].token == EOFTOKEN;
}

TokenInfo peek(Parser* parser)
{
    return parser->tokens[parser->index];
}

int num_match(NumLiteral num)
{
    switch (num)
    {
        case ZERO:
            return 0;
        case ONE:
            return 1;
        case TWO:
            return 2;
        case THREE:
            return 3;
        case FOUR:
            return 4;
        case FIVE:
            return 5;
        case SIX:
            return 6;
        case SEVEN:
            return 7;
        case EIGHT:
            return 8;
        case NINE:
            return 9;
    }
}
