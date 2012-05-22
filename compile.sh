#!/bin/bash
gcc -I/usr/include/SDL -c Window.c -lSDL
gcc -I/usr/include/SDL -o ../snake snake.c Window.o -lSDL
