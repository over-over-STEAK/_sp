#include <stdio.h>

int main(int argc, char **argv) {
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]); // 程式名稱

    if (argc > 1) {
        printf("argv[1] = %s\n", argv[1]); // 第一個參數（若有）
    } else {
        printf("未提供參數 argv[1]\n");
    }

    return 0;
}
