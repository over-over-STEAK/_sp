#include <stdio.h>

int sum(int n) {
  int s = 0;
  int i = 1;
  while (i <= n) {
    printf("start: i = %d, s = %d\n", i, s);
    s += i;
    printf("end:   i = %d, s = %d\n", i, s);
    i++;
  }
  return s;
}

int main() {
  printf("sum(10) = %d\n", sum(10));
  return 0;
}
