#include "AST.h"

AST *ast_new(AST ast)
{
    AST *ptr = malloc(sizeof(AST));
    if (ptr) *ptr = ast;
    return ptr;
}

void ast_free(AST *ptr) {
  AST ast = *ptr;
  switch (ast.tag) {
    case AST_NUMBER: {
      struct AST_NUMBER data = ast.data.AST_NUMBER;
      break;
    }
    case AST_ADD: {
      struct AST_ADD data = ast.data.AST_ADD;
      ast_free(data.left);
      ast_free(data.right);
      break;
    }
    case AST_MUL: {
      struct AST_MUL data = ast.data.AST_MUL;
      ast_free(data.left);
      ast_free(data.right);
      break;
    }
  } 
  free(ptr);
}

void ast_print(AST *ptr) {
  AST ast = *ptr;
  switch (ast.tag) {
    case AST_NUMBER: {
      struct AST_NUMBER data = ast.data.AST_NUMBER;
      printf("%d", data.number);
      return;
    }
    case AST_ADD: {
      struct AST_ADD data = ast.data.AST_ADD;
      printf("(");
      ast_print(data.left);
      printf(" + ");
      ast_print(data.right);
      printf(")");
      return;
    }
    case AST_MUL: {
      struct AST_MUL data = ast.data.AST_MUL;
      printf("(");
      ast_print(data.left);
      printf(" * ");
      ast_print(data.right);
      printf(")");
      return;
    }
  }
}
