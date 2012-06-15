#!/bin/bash
gcc -I/usr/include/SDL -o ../snake snake.c Window.c Snake.c Game.c Food.c RectCollection.c -lSDL
