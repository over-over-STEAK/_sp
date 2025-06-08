#include <stdio.h>

int mult3(int a, int b, int c); // 聲明由 mult.s 提供的函數

int main() {
    printf("mult3(3, 2, 5) = %d\n", mult3(3, 2, 5));
    return 0;
}
