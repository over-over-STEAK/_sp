#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    int i = 0;
    while (i < exp) {
        result *= base;
        i++;
    }
    return result;
}

int main() {
    int base = 3, exp = 2;
    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}

