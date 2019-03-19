#！/bin/sh
rm *.exe
g++ -o main.exe $1 -std=c++14
./main < in.txt