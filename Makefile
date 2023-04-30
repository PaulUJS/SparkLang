OBJS = spark.c Lexer/* 
CC = gcc

COMPILER_FLAGS = -w

LINKER_FLAGS = 

OBJ_NAME = a

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
      
    
