@echo off
echo [1] 產生 power.s
g++ -S power.cpp

echo [2] 產生 power.o
g++ -c power.cpp

echo [3] 反組譯 power.o（存入 power_disasm.txt）
objdump -d power.o > power_disasm.txt

echo [4] 編譯與執行 power.exe
g++ power.cpp -o power.exe
power.exe

pause
