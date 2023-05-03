#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"


TokenInfo* tokenize()
{
    bool wasspace = false;
    bool writing = false;

    // Token array variables
    size_t length = 1024;
    size_t index = 0;
    TokenInfo* array;
    array = malloc(sizeof(TokenInfo) * length);
    size_t line = 1;

    // String variables
    size_t str_index = 0;
    size_t str_len = 1024;
    char* str;
    str = malloc(str_len);

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
        if (is_at_end(index, &length))
        {
            array = realloc(array, sizeof(TokenInfo) * length);
        }
        if (is_at_end(str_index, &str_len))
        {
            str = realloc(str, str_len);
        }

        switch (ch)
        {
            case '(':
                array[index].token = LEFTPAREN;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case ')':
                array[index].token = RIGHTPAREN;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case '+':
                array[index].token = PLUS;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case '-':
                array[index].token = MINUS;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case '*':
                array[index].token = STAR;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case '/':
                array[index].token = SLASH;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case ';':
                array[index].token = SEMICOLON;
                array[index].line = line;
                array[index].num = NONE;
                array[index].lexeme = NULL;
                index += 1;
                wasspace = false;
                writing = false;
                break;
            case ':':
                ch = fgetc(ptr);
                if (ch == ':')
                {
                    array[index].token = COLONCOLON;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    wasspace = false;
                    writing = false;
                    break;
                }
                else {
                    if (!isspace(ch))
                        wasspace = false;
                    else
                        wasspace = true;
                    index += 1;
                    writing = false;
                    break;
                }
            case '!':
                ch = fgetc(ptr);
                if (ch == '=')
                {
                    array[index].token = BANGEQUAL;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    wasspace = false;
                    writing = false;
                    break;
                }
                else
                {
                    if (!isspace(ch))
                        wasspace = false;
                    else
                        wasspace = true;

                    array[index].token = BANG;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    writing = false;
                    break;
                }
            case '=':
                ch = fgetc(ptr);
                if (ch == '=')
                {
                    array[index].token = EQUALEQUAL;
                    array[index].line = line;
                    array[index].num = NONE;
                    index += 1;
                    wasspace = false;
                    array[index].lexeme = NULL;
                    writing = false;
                    break;
                }
                else
                {
                    if (!isspace(ch))
                        wasspace = false;
                    else
                        wasspace = true;

                    array[index].token = EQUAL;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    writing = false;
                    index += 1;
                    break;
                }
            case '<':
                ch = fgetc(ptr);
                if (ch == '=')
                {
                    array[index].token = LESSEQUAL;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    wasspace = false;
                    writing = false;
                    break;
                }
                else
                {
                    if (!isspace(ch))
                        wasspace = false;
                    else
                        wasspace = true;

                    array[index].token = LESS;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    writing = false;
                    break;
                }
            case '>':
                ch = fgetc(ptr);
                if (ch == '=')
                {
                    
                    array[index].token = GREATEREQUAL;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    wasspace = false;
                    writing = false;
                    break;
                }
                else
                {
                    if (!isspace(ch))
                        wasspace = false;
                    else
                        wasspace = true;

                    array[index].token = GREATER;
                    array[index].line = line;
                    array[index].num = NONE;
                    array[index].lexeme = NULL;
                    index += 1;
                    writing = false;
                    break;
                }
            default:
                if (isspace(ch) && wasspace == false || ch == '\n' && wasspace == false)
                {
                    if (ch == '\n')
                    {
                        line += 1;
                    }
                    str[str_index] = '\0';
                    wasspace = true;
                    str = realloc(str, str_index + 1);

                    if (strcmp(str, "u_int") == 0)
                    {
                        array[index].token = UINT;
                        array[index].line = line;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        str_index = 0;
                        index += 1;
                        writing = false;
                        break;
                    } 
                    else if (strcmp(str, "int") == 0)
                    {
                        array[index].token = INT;
                        array[index].line = line;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        str_index = 0;
                        index += 1;
                        writing = false;
                        break;
                    }
                    else if (strcmp(str, "u_float") == 0)
                    {
                        array[index].token = UFLOAT;
                        array[index].line = line;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        str_index = 0;
                        index += 1;
                        writing = false;
                        break;
                    }
                    else if (strcmp(str, "float") == 0)
                    {
                        array[index].token = FLOAT;
                        array[index].line = line;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        str_index = 0;
                        index += 1;     
                        writing = false;
                        break;
                    }
                    else if (strcmp(str, "string") == 0)
                    {
                        array[index].token = STRING;
                        array[index].line = line;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        str_index = 0;
                        index += 1;
                        writing = false;
                        break;
                    }
                    else if (strcmp(str, "char") == 0)
                    {
                        array[index].token = CHAR;
                        array[index].line = line;
                        str_index = 0;
                        array[index].num = NONE;
                        array[index].lexeme = NULL;
                        index += 1;
                        writing = false;
                        break;
                    }
                    else
                    {
                        if (writing == true)
                        {
                            array[index].token = STRLITERAL;
                            array[index].line = line;
                            array[index].num = NONE;
                            array[index].lexeme = str;
                            str_index = 0;
                            index += 1;
                        }
                        break;
                    }
                }
                else 
                {
                    if (isspace(ch))
                        wasspace = true;
                    else 
                    {
                        if (isdigit(ch))
                        {
                            array[index].token = NUMLITERAL;
                            array[index].line = line;
                            array[index].num = match_num(ch); 
                            array[index].lexeme = NULL;
                            str_index = 0;
                            index += 1;
                        }
                        else 
                        {
                            writing = true;
                        }
                        wasspace = false;
                        str[str_index] = ch;
                        str_index += 1;
                    }
                    break;
                }
        }
    }
    array[index].token = EOFTOKEN;
    array[index].line = line;
    array[index].num = NONE;
    array[index].lexeme = NULL;
    index += 1;

    fclose(ptr);
    array = realloc(array, sizeof(TokenInfo) * length + 1);

    free(str);
    print_tokens(array, index);
    return array;
}

NumLiteral match_num(char ch)
{
    switch (ch)
    {
        case '0':
            return ZERO;
        case '1':
            return ONE;
        case '2':
            return TWO;
        case '3':
            return THREE;
        case '4':
            return FOUR;
        case '5':
            return FIVE;
        case '6':
            return SIX;
        case '7':
            return SEVEN;
        case '8':
            return EIGHT;
        case '9':
            return NINE;
    }
}

void print_tokens(TokenInfo* arr, size_t index)
{
    for (int i = 0; i < index; i++)
    {
        switch (arr[i].token)
        {
            case 0:
                puts("U_INT");
                break;
            case 1:
                puts("INT");
                break;
            case 2:
                puts("U_FLOAT");
                break;
            case 3:
                puts("FLOAT");
                break;
            case 4:
                puts("STRING");
                break;
            case 5:
                puts("CHAR");
                break;
            case 6:
                puts("LEFTPAREN");
                break;
            case 7:
                puts("RIGHTPAREN");
                break;
            case 8:
                puts("COLONCOLON");
                break;
            case 9:
                puts("SEMICOLON");
                break;
            case 10:
                puts("PLUS");
                break;
            case 11:
                puts("MINUS");
                break;
            case 12:
                puts("STAR");
                break;
            case 13:
                puts("SLASH");
                break;
            case 14:
                puts("BANG");
                break;
            case 15:
                puts("BANGEQUAL");
                break;
            case 16:
                puts("EQUAL");
                break;
            case 17:
                puts("EQUALEQUAL");
                break;
            case 18:
                puts("LESS");
                break;
            case 19:
                puts("LESSEQUAL");
                break;
            case 20:
                puts("GREATER");
                break;
            case 21:
                puts("GREATEREQUAL");
                break;
            case 22:
                puts("NUMLITERAL");
                printf("%d \n", arr[i].num);
                break;
            case 23:
                puts("STRLITERAL");
                puts(arr[i].lexeme);
                break;
        }
    }
}


bool is_at_end(size_t index, size_t* length)
{
    if (index + 1 >= length)
    {
        *length * 2;
        return true;
    } 
    else {
        return false;
    }
}
