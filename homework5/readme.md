### 林家煒 111210564 

### power.cpp
#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int base = 3, exp = 2;
    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);
    return 0;
}


 ### 編譯與執行 power.cpp
sh
複製
編輯
g++ power.cpp
./a.exe
 ### 產生目的檔 .o
sh
複製
編輯
g++ -c power.cpp
##將該目的檔反組譯
sh
複製
編輯
objdump -d power.o
🔧 objdump 反組譯輸出
asm
複製
編輯
file format pe-i386

Disassembly of section .text:

00000000 <__Z5powerii>:
   0:   55                      push   %ebp
   1:   89 e5                   mov    %esp,%ebp
   3:   83 ec 10                sub    $0x10,%esp
   6:   c7 45 fc 01 00 00 00    movl   $0x1,-0x4(%ebp)
   d:   c7 45 f8 00 00 00 00    movl   $0x0,-0x8(%ebp)
  14:   8b 45 f8                mov    -0x8(%ebp),%eax
  17:   3b 45 0c                cmp    0xc(%ebp),%eax
  1a:   7d 10                   jge    2c <__Z5powerii+0x2c>
  1c:   8b 45 fc                mov    -0x4(%ebp),%eax
  1f:   0f af 45 08             imul   0x8(%ebp),%eax
  23:   89 45 fc                mov    %eax,-0x4(%ebp)
  26:   83 45 f8 01             addl   $0x1,-0x8(%ebp)
  2a:   eb e8                   jmp    14 <__Z5powerii+0x14>
  2c:   8b 45 fc                mov    -0x4(%ebp),%eax
  2f:   c9                      leave
  30:   c3                      ret

00000031 <_main>:
  31:   55                      push   %ebp
  32:   89 e5                   mov    %esp,%ebp
  34:   83 e4 f0                and    $0xfffffff0,%esp
  37:   83 ec 20                sub    $0x20,%esp
  3a:   e8 00 00 00 00          call   3f <_main+0xe>
  3f:   c7 44 24 1c 02 00 00    movl   $0x2,0x1c(%esp)
  46:   00
  47:   c7 44 24 18 03 00 00    movl   $0x3,0x18(%esp)
  4e:   00
  4f:   8b 44 24 18             mov    0x18(%esp),%eax
  53:   89 44 24 04             mov    %eax,0x4(%esp)
  57:   8b 44 24 1c             mov    0x1c(%esp),%eax
  5b:   89 04 24                mov    %eax,(%esp)
  5e:   e8 9d ff ff ff          call   0 <__Z5powerii>
  63:   89 44 24 14             mov    %eax,0x14(%esp)
  67:   8b 44 24 14             mov    0x14(%esp),%eax
  6b:   89 44 24 0c             mov    %eax,0xc(%esp)
  6f:   8b 44 24 18             mov    0x18(%esp),%eax
  73:   89 44 24 08             mov    %eax,0x8(%esp)
  77:   8b 44 24 1c             mov    0x1c(%esp),%eax
  7b:   89 44 24 04             mov    %eax,0x4(%esp)
  7f:   c7 04 24 00 00 00 00    movl   $0x0,(%esp)
  86:   e8 00 00 00 00          call   8b <_main+0x5a>
  8b:   b8 00 00 00 00          mov    $0x0,%eax
  90:   c9                      leave
  91:   c3                      ret
### 印出 .o 目的檔的表頭
sh
複製
編輯
objdump -h power.o
sh
複製
編輯
file format pe-i386

Sections:
Idx Name          Size      VMA       LMA       File off  Algn
  0 .text         00000094  00000000  00000000  00000104  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, CODE
  1 .data         00000000  00000000  00000000  00000000  2**2
                  ALLOC, LOAD, DATA
  2 .bss          00000000  00000000  00000000  00000000  2**2
                  ALLOC
  3 .rdata        0000000c  00000000  00000000  00000198  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .rdata$zzz    00000024  00000000  00000000  000001a4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .eh_frame     00000058  00000000  00000000  000001c8  2**2
                  CONTENTS, ALLOC, LOAD, RELOC, READONLY, DATA
