#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token and token list structures
typedef struct Token {
    int type;
    char* value;
} Token;

typedef struct TokenList {
    Token* tokens;
    int size;
} TokenList;

// Parser interface
TokenList* tokenize(const char* source_code);

#endif // PARSER_H
