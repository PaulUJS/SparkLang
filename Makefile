OBJS = spark.c Lexer/* Parser/* AST/*
CC = gcc

COMPILER_FLAGS = -w

LINKER_FLAGS = 

OBJ_NAME = a

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
      
    
