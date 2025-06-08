#include <stdio.h>
#include <string.h>
#include "interpreter.h"

char line[256];

int main() {
    printf("歡迎使用 C 語言簡易直譯器！輸入 'exit' 離開\n");
    while (1) {
        printf(">>> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        if (strncmp(line, "exit", 4) == 0) break;

        reset_lexer(line);
        AST *stmt = parse_statement();
        if (stmt) {
            eval(stmt);
            free_ast(stmt);
        }
    }
    return 0;
}
