#include <stdio.h>

int tail_fib(int n, int a, int b) {
  if (n == 0) return a;
  if (n == 1) return b;
  return tail_fib(n - 1, b, a + b);
}

int f(int n) {
  return tail_fib(n, 0, 1);
}

int main() {
  printf("f(7) = %d\n", f(7));
  return 0;
}
