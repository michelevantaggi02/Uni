#!/bin/bash
gcc -pthread main.c
chmod +x a.out
./a.out $1 $2 $3 $4