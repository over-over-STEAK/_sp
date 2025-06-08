set -x  # 開啟 bash 逐行輸出除錯模式

gcc -g -w c4.c -o c4  # 加上 -g 表示帶有除錯符號，禁用所有警告

# 以下是 -s 模式，將 C 檔轉換成虛擬機指令集（symbolic dump）
./c4 -s hello.c
./c4 -s test/bottom.c
./c4 -s test/sum.c
./c4 -s test/for.c
# ./c4 -s test/for2.c  # 目前註解掉，可能語法錯誤或尚未測試

# 執行特定檔案並顯示 output 結果
./c4 test/for.c

# 下面幾行測試其他功能（符號表、執行 while、hello）
# ./c4 -u test/while.c
# ./c4 test/bottom.c
# ./c4 hello.c

# 執行 c4 自我編譯 + hello 測試
./c4 c4.c hello.c

# 多次執行 c4 自我編譯與 hello（測試累積效能與 cycle）
./c4 c4.c c4.c hello.c
