#include <stdio.h>

extern int power(int base, int exp);

int main() {
    int base = 3, exp = 2;
    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}

