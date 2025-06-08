# 🎓 期中期末整合報告
**學號**：111210564  
**姓名**：林家煒  
**系級**：資工二  

---

## 📚 學期統整
- [homework-1](https://github.com/over-over-STEAK/_sp/tree/sp/homework1)
- [homework-2](https://github.com/over-over-STEAK/_sp/tree/sp/homework2)
- [homework-3](https://github.com/over-over-STEAK/_sp/tree/sp/homework3)
- [homework-4](https://github.com/over-over-STEAK/_sp/tree/sp/homework4)
- [homework-5](https://github.com/over-over-STEAK/_sp/tree/sp/homework5)
- [Midterm專案](https://github.com/over-over-STEAK/_sp/tree/sp/Miderm)

---

## 🧩 homework-1：do-while 與詞彙分析器

### ✅ do...while 語法
```c
do {
    // 執行區塊
} while (條件);
```

### ✅ 詞彙分析器 scan 函式
```c
char *scan() {
  while (isspace(*p)) p++;

  char *start = p;
  int type;
  if (*p == '"') {
    p++; while (*p != '"') p++; p++;
    type = Literal;
  } else if (isdigit(*p)) {
    while (isdigit(*p)) p++;
    type = Int;
  } else if (isalpha(*p) || *p == '_') {
    while (isalnum(*p) || *p == '_') p++;
    type = Id;
  } else if (strchr("+-*/%%&|<>!=", *p)) {
    char c = *p++;
    if (*p == '=') p++;
    else if (strchr("+-&|", c) && *p == c) p++;
    type = Op;
  } else {
    p++; type = Char;
  }

  int len = p - start;
  strncpy(token, start, len);
  token[len] = '\0';
  return token;
}
```

---

## 🔢 homework-2：power2 函式與中間碼分析
```c
int power2(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}
```

### ✅ C4 虛擬機中間碼 (精簡片段)
```
ENT 2
LLA -1
IMM 1
SI
LLA -2
IMM 0
SI
...
IMM 2
MUL
SI
```

---

## 🔁 homework-3：AsmFib 組合碼分析

### ✅ fib 函式邏輯
```c
int f(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  return f(n-1) + f(n-2);
}
```

### ✅ 結果展示
```
f(7) = 13
exit(8) cycle = 920
```

---

## 🧠 homework-4：if 條件語句支援

### ✅ 支援程式碼（節錄）
```c
if (lookahead.type == TOKEN_IDENTIFIER && strcmp(lookahead.text, "if") == 0) {
    advance();
    AST *cond = parse_expr();
    AST *node = malloc(sizeof(AST));
    node->kind = AST_IF;
    node->expr = cond;
    return node;
}
```

```c
case AST_IF: {
    int cond = eval(node->expr);
    if (cond) printf("條件成立\n");
    return 0;
}
```

---

## 🔁 homework-5：while 迴圈支援

### ✅ 測試程式碼
```c
x = 3
while x print x x = x - 1
```

### ✅ 評估邏輯
```c
case AST_WHILE: {
    while (eval(node->left)) {
        eval(node->right);
    }
    return 0;
}
```

---

## 🧪 Midterm：C 語言直譯器六大模組整合

| 檔案名稱         | 功能描述                     |
|------------------|------------------------------|
| `main.c`         | 主函式與 REPL                |
| `lexer.c`        | 字元轉 Token                  |
| `parser.c`       | Token 轉 AST                 |
| `eval.c`         | AST 執行邏輯                 |
| `symbol_table.c` | 符號表維護變數資料           |
| `interpreter.h`  | 定義 Token/AST 結構與函式原型 |

---

**補充說明**：  
所有實作皆參考同學討論、課堂講解與 AI 工具（ChatGPT、GhatGpt、Deepseek 等）輔助完成，並於終端實測驗證語意正確性。
