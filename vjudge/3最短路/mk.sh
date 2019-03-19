#!/bin/sh
g++ -o main.exe $1 -std=c++98
./main.exe < in.txt

