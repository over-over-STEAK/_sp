# include <stdio.h>

int power2(int n) {
    if (n < 0) {
        return -1;
    }
    return 1 << n;
}

int main() {
    int n;
    printf("請輸入一個非負整數 n：");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("輸入錯誤，請輸入非負整數。\n");
        return 1;
    }

    int result = power2(n);
    if (result == -1) {
        printf("無效輸入，n 不能是負數。\n");
    } else {
        printf("2 的 %d 次方是 %d\n", n, result);
    }
    
    return 0;
}
