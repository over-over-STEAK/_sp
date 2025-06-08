#include <stdio.h>

// mult3 是在外部組合語言檔定義的
int mult3(int a, int b, int c);

int main() {
    printf("mult3(3,2,5)=%d\n", mult3(3, 2, 5));
    return 0;
}
