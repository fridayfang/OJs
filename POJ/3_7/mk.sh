#!/bin/sh
rm *.exe
g++ -o main.exe $1 -std=c++98
./main < in.txt