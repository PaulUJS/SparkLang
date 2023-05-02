#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>
#include <stddef.h>

typedef enum {

    // Types
    UINT,
    INT,
    UFLOAT,
    FLOAT,
    STRING,
    CHAR,

    // Symbols
    LEFTPAREN,
    RIGHTPAREN,
    COLONCOLON,
    SEMICOLON,

    // Operators
    PLUS,
    MINUS,
    STAR,
    SLASH,
    BANG,
    BANGEQUAL,
    EQUAL,
    EQUALEQUAL,
    LESS,
    LESSEQUAL,
    GREATER,
    GREATEREQUAL,

} Token;

typedef struct {
    Token token;
    size_t line;
} TokenInfo;

TokenInfo* tokenize();
bool is_at_end(size_t index, size_t* length);
void print_tokens(TokenInfo* arr, size_t index);

#endif
