#!/bin/bash
echo "編譯 power.cpp 成 .s 組合檔..."
g++ -S power.cpp

echo "編譯 power.cpp 成目標檔..."
g++ -c power.cpp

echo "反組譯 power.o："
objdump -d power.o > power_disasm.txt
echo "（輸出已存到 power_disasm.txt）"

echo " 編譯並執行程式..."
g++ power.cpp -o power
./power
