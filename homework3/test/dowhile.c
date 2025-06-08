#include <stdio.h>

int sum(int n) {
    int i = 1, s = 0;
    do {
        s = s + i;
        i++;
    } while(i <= n);
    return s;
}

int main() {
    printf("sum(10) = %d\n", sum(10));
    return 0;
}
