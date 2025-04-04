<pre>
# File with heading

++ gcc -w c4_asmpower2.c -o c4_asmpower2
c4_asmpower2.c: In function 'main':
c4_asmpower2.c:97:3: error: 'n' undeclared (first use in this function)
1> ENT 0
2> IMM 25
3> PSH
4> IMM 111
5> PSH
6> JSR 0x0048
7> ENT 0
8> LLA 2
9> LI
10> PSH
11> IMM 333
12> EQ
13> BZ 0x0020
14> IMM 25
15> PSH
16> LLA 2
17> LI
18> PSH
19> IMM 1
20> SUB
21> PSH
22> JSR 0x0048
23> ENT 0
24> LLA 2
25> LI
26> PSH
27> IMM 333
28> EQ
29> BZ 0x0020
...
94> IMM 25
95> LEV
96> ADJ 1
97> ADD
98> LEV
99> ADJ 1
100> ADD
101> LEV
102> ADJ 1
103> ADD
104> LEV
105> ADJ 1
106> ADD
107> LEV
108> ADJ 1
109> ADD
110> LEV
111> ADJ 1
112> PSH
113> PRTF 32
114> ADJ 2
115> LEV
116> PSH
117> IMM 300
118> PRTF "The answer is: 300\n"
119> EXIT
