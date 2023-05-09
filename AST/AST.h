#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <ctype.h>

#define AST_NEW(tag, ...) \
  ast_new((AST){tag, {.tag=(struct tag){__VA_ARGS__}}})

typedef struct AST AST; // Forward reference

struct AST {
  enum {
    AST_NUMBER,
    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
  } tag;
  union {
    struct AST_NUMBER { int number; } AST_NUMBER;
    struct AST_ADD { AST *left; AST *right; } AST_ADD;
    struct AST_SUB { AST *left; AST *right; } AST_SUB;
    struct AST_MUL { AST *left; AST *right; } AST_MUL;
    struct AST_DIV { AST *left; AST *right; } AST_DIV;
  } data;
};

AST *ast_new(AST ast);
void ast_free(AST *ptr);
void ast_print(AST *ptr);

#endif
