#include <stdio.h>

int mult3(int a, int b, int c) {
    int result;
    __asm__ (
        "imull %2, %1\n"   // a * b → b
        "imull %3, %1\n"   // b * c → b
        "movl %1, %0\n"    // result = b
        : "=r" (result)    // output
        : "r" (a), "r" (b), "r" (c) // inputs
    );
    return result;
}

int main() {
    printf("mult3(3,2,5)=%d\n", mult3(3, 2, 5));
    return 0;
}
