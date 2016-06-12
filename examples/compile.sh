#! /bin/bash

make clean
make
gcc -Wall -c main.c -o main.o
gcc -Wall main.o ../obj/rasp_uart.o -o main.elf -lpthread
