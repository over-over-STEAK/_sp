#!/bin/bash
set -x

# 編譯
gcc -g -Wall c4.c -o c4

# 測試個別檔案（使用自訂 -s 模式）
./c4 -s hello.c
./c4 -s bottom/.c
./c4 -s test/sum.c
./c4 -s test/for.c
./c4 -s test/for2.c


./c4 test/for.c
./c4 hello.c

# 測試多檔案
./c4 c4.c hello.c

#（若需要其他模式，如 -u，請確認 c4.c 有處理）
# ./c4 -u test/fib.c
