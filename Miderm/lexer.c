#include <ctype.h>
#include <string.h>
#include "interpreter.h"

static const char *src;
static Token current;

void reset_lexer(const char *input) {
    src = input;
}

Token get_next_token() {
    while (isspace(*src)) src++;

    if (*src == '\0') return (Token){TOKEN_EOF, ""};
    if (isdigit(*src)) {
        int i = 0;
        while (isdigit(*src)) current.text[i++] = *src++;
        current.text[i] = '\0';
        current.type = TOKEN_NUMBER;
        return current;
    }
    if (isalpha(*src)) {
        int i = 0;
        while (isalnum(*src)) current.text[i++] = *src++;
        current.text[i] = '\0';
        if (strcmp(current.text, "print") == 0)
            current.type = TOKEN_PRINT;
        else
            current.type = TOKEN_IDENTIFIER;
        return current;
    }
    if (*src == '=') {
        src++;
        return (Token){TOKEN_ASSIGN, "="};
    }
    if (strchr("+-*/()", *src)) {
        current.type = TOKEN_OPERATOR;
        current.text[0] = *src++;
        current.text[1] = '\0';
        return current;
    }

    src++; // skip unknown
    return (Token){TOKEN_EOF, ""};
}
