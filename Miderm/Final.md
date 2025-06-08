### 期中期末整合
111210564_資工二_林家煒
### 學期統整

[homework-1](https://github.com/over-over-STEAK/_sp/tree/sp/homework1)
功課來源ai 加上網頁設計進階檔案靈感 Deepseek GhtGpt
### 說明
這題首先要知道do-while的寫法，do-while是一種先執行後判斷的迴圈結構，其基本語法如下：
do...while 迴圈，其語法結構是：

c
複製
編輯
do {
    // 執行區塊
} while (條件);
解釋：
do：先執行一次大括號內的程式碼。

while (條件)：每次執行完區塊後會檢查條件，若為 true（非 0），則重複執行；若為 false（0），則結束。

特點：
至少會執行一次區塊內的程式碼（這是 do...while 和 while 最大的差別）。
變數名稱	說明
code	儲存整段程式碼文字內容。
p	指向目前字元的指標（掃描進度用）。
token	暫存當前擷取的詞彙（最大長度 LMAX）。
strTable	存放所有詞彙字串（避免被覆蓋）。
tokens[]	指向 strTable 中每個 token 的指標。
tokenTop	記錄目前存了幾個 token。

scan() 函式解析：
這是核心掃描函式，主要步驟如下：

c
複製
編輯
while (isspace(*p)) p++;
🔸 跳過空白與換行符號。

 掃描 Literal 字串（字串常數）
c
複製
編輯
if (*p == '"') {
    p++;
    while (*p != '"') p++;
    p++;
    type = Literal;
}
🔸 偵測雙引號包圍的字串，例如 "Hello"。

 掃描整數
c
複製
編輯
else if (*p >= '0' && *p <= '9') {
    while (*p >= '0' && *p <= '9') p++;
    type = Int;
}
🔸 如果是數字開頭，掃描完整的數字，如 12345。

 掃描識別字（變數或關鍵字）
c
複製
編輯
else if (isAlpha(*p) || *p == '_') {
    while (isAlpha(*p) || isDigit(*p) || *p == '_') p++;
    type = Id;
}
🔸 如果是字母或底線開頭，掃描一整個合法識別字。

掃描運算符號
c
複製
編輯
else if (strchr("+-*/%%&|<>!=", *p) >= 0) {
    char c = *p++;
    if (*p == '=') p++;
    else if (strchr("+-&|", c) >= 0 && *p == c) p++;
    type = Op;
}
🔸 可處理單字元與雙字元運算子（如 +, -, +=, ==, &&）。

其他單一字元（如 (, ;）
c
複製
編輯
else {
    p++;
    type = Char;
}
🔸 其他未被上述涵蓋的單一字元，如括號、分號等。

將 token 存進暫存區
c
複製
編輯
int len = p - start;
strncpy(token, start, len);
token[len] = '\0';
🔸 將擷取到的字串複製到 token，並回傳這個詞彙。
 lex(char *code) 函式流程：
c
複製
編輯
p = code;
tokenTop = 0;
while (1) {
  char *tok = scan();
  if (tok == NULL) break;
  strcpy(strTableEnd, tok);
  tokens[tokenTop++] = strTableEnd;
  strTableEnd += (strlen(tok) + 1);
  printf("token=%s\n", tok);
}
🔹 重設指標 → 持續掃描 → 存到 tokens[] → 印出。
輸入：

c
複製
編輯
char *code = "int x = 10 + 20;";
lex(code);
輸出：

makefile
複製
編輯
========== lex ==============
token=int
token=x
token==
token=10
token=+
token=20
token=;

[homework-2](https://github.com/over-over-STEAK/_sp/tree/sp/homework2)
首先，讓我們看一下power2函數的C語言實作：

int power2(int n) {
    int r, i;
    r = 1;
    i = 1;
    while (i<=n) {
        r = r*2;
        i++;
    }
    return r;
}
接著，我們分析c4虛擬機生成的組合語言代碼：

ENT 2       // 進入函數，分配2個區域變數空間
LLA -1      // 載入r的地址（第一個區域變數）
PSH         // 將地址推入堆疊
IMM 1       // 載入立即數1
SI          // 將1存入r (r = 1)

LLA -2      // 載入i的地址（第二個區域變數）
PSH         // 將地址推入堆疊
IMM 1       // 載入立即數1
SI          // 將1存入i (i = 1)

// while (i<=n) 的條件判斷
LLA -2      // 載入i的地址
LI          // 載入i的值
PSH         // 將i的值推入堆疊
LLA 2       // 載入n的地址（函數參數）
LI          // 載入n的值
LE          // 比較 i <= n
BZ 0        // 如果不成立，跳到標籤0（迴圈結束）

// r = r*2
LLA -1      // 載入r的地址
PSH         // 將地址推入堆疊
LLA -1      // 再次載入r的地址
LI          // 載入r的值
PSH         // 將r的值推入堆疊
IMM 2       // 載入立即數2
MUL         // 計算 r * 2
SI          // 將結果存回r

// i++
LLA -2      // 載入i的地址
PSH         // 將地址推入堆疊
LI          // 載入i的值
PSH         // 將i的值推入堆疊
IMM 1       // 載入立即數1
ADD         // 計算 i + 1
SI          // 將結果存回i

// 跳回迴圈開始處
JMP xxx     // 跳回迴圈條件判斷處

// return r
LLA -1      // 載入r的地址
LI          // 載入r的值
LEV         // 離開函數，返回r的值
 

[homework-3](https://github.com/over-over-STEAK/_sp/tree/sp/homework3)
ai 參考為主
這些是 c4 虛擬機的「指令碼」形式，用來執行程式邏輯：

less
複製
編輯
ENT     0        // 進入函式，為 f 或 main 開場（建立堆疊框架）
LLA     2        // 載入變數位置（參數 n）
LI               // 載入 n 的值
IMM    0         // 常數 0
LE               // 比較 n <= 0
BZ     0         // 如果不是，就跳過 return 0
IMM    0
LEV              // return 0;

...（略）

JSR   1342472200 // 呼叫函式（jump to subroutine）f(n-1) 或 f(n-2)
這些都是虛擬機中定義的語法符號指令，執行時會根據這些中間碼模擬整個 C 程式。

[homework-4](https://github.com/over-over-STEAK/_sp/tree/sp/homework4)
這是一段用 x86-64 組合語言 寫的簡單函式 mult3，功能是：

將三個整數相乘，並將結果回傳。

這段程式碼可以被 C 語言呼叫，例如：

c
複製
編輯
extern long mult3(long a, long b, long c);
printf("%ld\n", mult3(2, 3, 4));  // 輸出 24
📦 組合語碼說明
asm
複製
編輯
.global mult3
.text
.global mult3：宣告 mult3 為全域符號（能被外部 C 調用）。

.text：進入程式碼區段。

🔧 函式內容
asm
複製
編輯
mult3:
    mov     %rdi, %rax        # 把第一個參數 a 複製到 rax
    imul    %rsi, %rax        # rax *= 第二個參數 b
    imul    %rdx, %rax        # rax *= 第三個參數 c
    ret                       # return rax
🔹 寄存器說明（依照 x86-64 Linux calling convention）：
參數位置	參數名稱	寄存器
第 1 個	a	%rdi
第 2 個	b	%rsi
第 3 個	c	%rdx
回傳值	result	%rax 

[homework-5](https://github.com/over-over-STEAK/_sp/tree/sp/homework5)
產生組合語言.s檔
```
g++ -S main.cpp
```
執行power.cpp
```
g++ mian.cpp
 ./a.exe
```
產生目的檔.o檔
```
g++ -c power.cpp
```
將該目的檔反組譯
```
objdump -d power.o
```
```sh
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
  92:   90                      nop
  93:   90                      nop
```
印出該目的檔的表頭
```
objdump -h power.o
```
```sh
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
```

[Midterm](https://github.com/over-over-STEAK/_sp/tree/sp/Miderm)
需要下載附件 在終端機進行  為ai回答 使用gpt
### C 語言簡易直譯器專案 - 六大檔案說明

## 專案檔案列表

| 檔案名稱         | 功能描述                     |
|------------------|------------------------------|
| `main.c`         | 主函式與 REPL 介面            |
| `lexer.c`        | 將字串分割成 Token            |
| `parser.c`       | 將 Token 建立成 AST           |
| `eval.c`         | AST 的運算與執行邏輯          |
| `symbol_table.c` | 儲存與查詢變數的 Symbol Table |
| `interpreter.h`  | 公用結構定義與函式宣告        |

---

## 🔸 main.c

```c
#include <stdio.h>
#include <string.h>
#include "interpreter.h"

char line[256];

int main() {
    printf("歡迎使用 C 語言簡易直譯器！輸入 'exit' 離開\n");
    while (1) {
        printf(">>> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        if (strncmp(line, "exit", 4) == 0) break;

        reset_lexer(line);
        AST *stmt = parse_statement();
        if (stmt) {
            eval(stmt);
            free_ast(stmt);
        }
    }
    return 0;
}
```

---

## 🔸 lexer.c

```c
#include <ctype.h>
#include <string.h>
#include "interpreter.h"

static const char *src;
static Token current;

void reset_lexer(const char *input) {
    src = input;
}

Token get_next_token() {
    while (isspace(*src)) src++;

    if (*src == '\0') return (Token){TOKEN_EOF, ""};
    if (isdigit(*src)) {
        int i = 0;
        while (isdigit(*src)) current.text[i++] = *src++;
        current.text[i] = '\0';
        current.type = TOKEN_NUMBER;
        return current;
    }
    if (isalpha(*src)) {
        int i = 0;
        while (isalnum(*src)) current.text[i++] = *src++;
        current.text[i] = '\0';
        if (strcmp(current.text, "print") == 0)
            current.type = TOKEN_PRINT;
        else
            current.type = TOKEN_IDENTIFIER;
        return current;
    }
    if (*src == '=') {
        src++;
        return (Token){TOKEN_ASSIGN, "="};
    }
    if (strchr("+-*/()", *src)) {
        current.type = TOKEN_OPERATOR;
        current.text[0] = *src++;
        current.text[1] = '\0';
        return current;
    }

    src++; // skip unknown
    return (Token){TOKEN_EOF, ""};
}
```

---

## 🔸 parser.c

```c
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"

static Token lookahead;

static void advance() {
    lookahead = get_next_token();
}

static AST *parse_expr();

static AST *parse_primary() {
    if (lookahead.type == TOKEN_NUMBER) {
        AST *node = malloc(sizeof(AST));
        node->kind = AST_NUM;
        node->value = atoi(lookahead.text);
        advance();
        return node;
    } else if (lookahead.type == TOKEN_IDENTIFIER) {
        AST *node = malloc(sizeof(AST));
        node->kind = AST_VAR;
        strcpy(node->name, lookahead.text);
        advance();
        return node;
    }
    return NULL;
}

static AST *parse_term() {
    AST *node = parse_primary();
    while (lookahead.type == TOKEN_OPERATOR &&
           (lookahead.text[0] == '*' || lookahead.text[0] == '/')) {
        char op = lookahead.text[0];
        advance();
        AST *right = parse_primary();
        AST *newnode = malloc(sizeof(AST));
        newnode->kind = AST_BINOP;
        newnode->op = op;
        newnode->left = node;
        newnode->right = right;
        node = newnode;
    }
    return node;
}

static AST *parse_expr() {
    AST *node = parse_term();
    while (lookahead.type == TOKEN_OPERATOR &&
           (lookahead.text[0] == '+' || lookahead.text[0] == '-')) {
        char op = lookahead.text[0];
        advance();
        AST *right = parse_term();
        AST *newnode = malloc(sizeof(AST));
        newnode->kind = AST_BINOP;
        newnode->op = op;
        newnode->left = node;
        newnode->right = right;
        node = newnode;
    }
    return node;
}

AST *parse_statement() {
    advance();
    if (lookahead.type == TOKEN_IDENTIFIER) {
        Token var = lookahead;
        advance();
        if (lookahead.type == TOKEN_ASSIGN) {
            advance();
            AST *rhs = parse_expr();
            AST *node = malloc(sizeof(AST));
            node->kind = AST_ASSIGN;
            strcpy(node->name, var.text);
            node->expr = rhs;
            return node;
        }
    }
    if (lookahead.type == TOKEN_PRINT) {
        advance();
        AST *expr = parse_expr();
        AST *node = malloc(sizeof(AST));
        node->kind = AST_PRINT;
        node->expr = expr;
        return node;
    }
    return NULL;
}

void free_ast(AST *node) {
    if (!node) return;
    if (node->kind == AST_BINOP) {
        free_ast(node->left);
        free_ast(node->right);
    } else if (node->kind == AST_ASSIGN || node->kind == AST_PRINT) {
        free_ast(node->expr);
    }
    free(node);
}
```

---

## 🔸 eval.c

```c
#include <stdio.h>
#include "interpreter.h"

int eval(AST *node) {
    if (!node) return 0;
    switch (node->kind) {
        case AST_NUM:
            return node->value;
        case AST_VAR:
            return get_variable(node->name);
        case AST_BINOP: {
            int l = eval(node->left);
            int r = eval(node->right);
            switch (node->op) {
                case '+': return l + r;
                case '-': return l - r;
                case '*': return l * r;
                case '/': return r ? l / r : 0;
            }
        }
        case AST_ASSIGN: {
            int val = eval(node->expr);
            set_variable(node->name, val);
            return val;
        }
        case AST_PRINT: {
            int val = eval(node->expr);
            printf("%d\n", val);
            return val;
        }
    }
    return 0;
}
```

---

## 🔸 symbol_table.c

```c
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[64];
    int value;
} Var;

static Var vars[100];
static int var_count = 0;

void set_variable(const char *name, int value) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            vars[i].value = value;
            return;
        }
    }
    strcpy(vars[var_count].name, name);
    vars[var_count].value = value;
    var_count++;
}

int get_variable(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return vars[i].value;
        }
    }
    return 0;
}
```

---

## 🔸 interpreter.h

```c
#ifndef INTERPRETER_H
#define INTERPRETER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_ASSIGN,
    TOKEN_PRINT,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char text[64];
} Token;

Token get_next_token();
void reset_lexer(const char *input);

typedef struct AST {
    enum { AST_NUM, AST_VAR, AST_BINOP, AST_ASSIGN, AST_PRINT } kind;
    union {
        int value;
        char name[64];
        struct {
            char op;
            struct AST *left;
            struct AST *right;
        };
        struct AST *expr;
    };
} AST;

AST *parse_statement();
void free_ast(AST *node);
int eval(AST *node);
void set_variable(const char *name, int value);
int get_variable(const char *name);

#endif
```
