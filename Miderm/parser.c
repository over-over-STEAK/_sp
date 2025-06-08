#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

static Token lookahead;

static void advance() {
    lookahead = get_next_token();
}

static AST *parse_expr();

static AST *parse_primary() {
    if (lookahead.type == TOKEN_NUMBER) {
        AST *node = malloc(sizeof(AST));
        node->kind = AST_NUM;
        node->value = atoi(lookahead.text);
        advance();
        return node;
    } else if (lookahead.type == TOKEN_IDENTIFIER) {
        AST *node = malloc(sizeof(AST));
        node->kind = AST_VAR;
        strcpy(node->name, lookahead.text);
        advance();
        return node;
    }
    return NULL;
}

static AST *parse_term() {
    AST *node = parse_primary();
    while (lookahead.type == TOKEN_OPERATOR &&
           (lookahead.text[0] == '*' || lookahead.text[0] == '/')) {
        char op = lookahead.text[0];
        advance();
        AST *right = parse_primary();
        AST *newnode = malloc(sizeof(AST));
        newnode->kind = AST_BINOP;
        newnode->op = op;
        newnode->left = node;
        newnode->right = right;
        node = newnode;
    }
    return node;
}

static AST *parse_expr() {
    AST *node = parse_term();
    while (lookahead.type == TOKEN_OPERATOR &&
           (lookahead.text[0] == '+' || lookahead.text[0] == '-')) {
        char op = lookahead.text[0];
        advance();
        AST *right = parse_term();
        AST *newnode = malloc(sizeof(AST));
        newnode->kind = AST_BINOP;
        newnode->op = op;
        newnode->left = node;
        newnode->right = right;
        node = newnode;
    }
    return node;
}

AST *parse_statement() {
    advance();
    if (lookahead.type == TOKEN_IDENTIFIER) {
        Token var = lookahead;
        advance();
        if (lookahead.type == TOKEN_ASSIGN) {
            advance();
            AST *rhs = parse_expr();
            AST *node = malloc(sizeof(AST));
            node->kind = AST_ASSIGN;
            strcpy(node->name, var.text);
            node->expr = rhs;
            return node;
        }
    }
    if (lookahead.type == TOKEN_PRINT) {
        advance();
        AST *expr = parse_expr();
        AST *node = malloc(sizeof(AST));
        node->kind = AST_PRINT;
        node->expr = expr;
        return node;
    }
    return NULL;
}

void free_ast(AST *node) {
    if (!node) return;
    if (node->kind == AST_BINOP) {
        free_ast(node->left);
        free_ast(node->right);
    } else if (node->kind == AST_ASSIGN || node->kind == AST_PRINT) {
        free_ast(node->expr);
    }
    free(node);
}
