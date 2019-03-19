#!/bin/sh
rm *.exe
g++ -o main.exe $1 -std=c++11
./main < in.txt