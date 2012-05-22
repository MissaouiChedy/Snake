snake: Window.o Food.o RectCollection.o
	gcc -I/usr/include/SDL -o ../snake snake.c Window.o Food.o RectCollection.o -lSDL
Window.o: 
	gcc -I/usr/include/SDL -c Window.c -lSDL
Food.o:
	gcc -I/usr/include/SDL -c Food.c -lSDL
RectCollection.o:
	gcc -I/usr/include/SDL -c RectCollection.c -lSDL
	
