#include "parser.h"
#include <ctype.h>

TokenList* tokenize(const char* source_code) {
    TokenList* tokens = (TokenList*)malloc(sizeof(TokenList));
    tokens->tokens = (Token*)malloc(sizeof(Token));
    tokens->size = 0;

    int i = 0;
    while (source_code[i] != '\0') {
        if (source_code[i] == ' ' || source_code[i] == '\t' || source_code[i] == '\n') {
            i++;
            continue;
        }
        int j = i;
        while (j < strlen(source_code) && (isalnum(source_code[j]) || source_code[j] == '_')) {
            j++;
        }
        Token* new_token = (Token*)malloc(sizeof(Token));
        new_token->type = source_code[i] == ' ' ? 0 : 1;
        new_token->value = (char*)malloc(sizeof(char) * (j - i + 1));
        strncpy(new_token->value, &source_code[i], j - i);
        new_token->value[j - i] = '\0';
        tokens->tokens = (Token*)realloc(tokens->tokens, (tokens->size + 1) * sizeof(Token));
        tokens->tokens[tokens->size++] = *new_token;
        free(new_token);
        i = j;
    }
    return tokens;
}
