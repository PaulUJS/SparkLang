#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "lexer.h"

#define LOWER 1024
#define UPPER 65536

void tokenize()
{
    // Token array variables
    size_t index = 0;
    size_t increased_t = LOWER;
    size_t allocated_t = increased_t;
    size_t line = 1;
    TokenInfo* array = malloc(sizeof(TokenInfo) * allocated_t);

    // String variables
    size_t total = 0;
    size_t increase = LOWER;
    size_t allocated = increase;
    char* str = malloc(allocated);

    FILE* ptr;
    char ch;
    ptr = fopen("test.txt", "r");

    if (ptr == NULL)
    {
        printf("File couldn't be opened \n");
    }

    while (!feof(ptr))
    {
        ch = fgetc(ptr);
        printf("%c", ch);
        if (is_at_end(index, allocated_t))
        {
            if (increased_t >= UPPER)
            {
                increased_t = UPPER;
            }
            allocated_t += increased_t;
            array = realloc(array, allocated_t);
            increased_t *= 2;
        }
        if (is_at_end(total, allocated))
        {
            if (increase >= UPPER) 
            {
                increase = UPPER;
            }
            allocated += increase;
            str = realloc(str, allocated);
            increase *= 2;
        }

        
        switch (ch)
        {
            case '(':
                array[index].token = LEFTPAREN;
                array[index].line = line;
                index += 1;
                break;
            case ')':
                array[index].token = RIGHTPAREN;
                array[index].line = line;
                index += 1;
                break;
            case '+':
                array[index].token = PLUS;
                array[index].line = line;
                index += 1;
                break;
            case '-':
                array[index].token = MINUS;
                array[index].line = line;
                index += 1;
                break;
            case '*':
                array[index].token = STAR;
                array[index].line = line;
                index += 1;
                break;
            case '/':
                array[index].token = SLASH;
                array[index].line = line;
                index += 1;
                break;
            case '\n':
                line += 1;
                break;
            default:
                if (isspace(ch))
                {
                    str = realloc(str, total);
                    if (strcmp(str, "u_int") == 0)
                    {
                        array[index].token = UINT;
                        array[index].line = line;
                        index += 1;
                        total = 0;
                    } 
                    else if (strcmp(str, "int") == 0)
                    {
                        array[index].token = INT;
                        array[index].line = line;
                        index += 1;
                        total = 0;

                    }
                    else if (strcmp(str, "u_float") == 0)
                    {
                        array[index].token = UFLOAT;
                        array[index].line = line;
                        index += 1;
                        total = 0;

                    }
                    else if (strcmp(str, "float") == 0)
                    {
                        array[index].token = FLOAT;
                        array[index].line = line;
                        index += 1;
                        total = 0;
               
                    }     
                }
                else {
                    str[total] = ch;
                    total += 1;
                }
                break;
        }


    }
    fclose(ptr);
    array = realloc(array, sizeof(TokenInfo) * allocated_t);

    for (int i = 0; i < index; i++)
    {
        printf("(%d) \n", array[i].token);
    }
    free(array);
    free(str);
}

bool is_at_end(size_t index, size_t length)
{
    if (index >= length)
    {
        return true;
    } 
    else if (index < length) {
        return false;
    }
}
