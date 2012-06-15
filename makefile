#snake: Window.o Snake.o Food.o
#	gcc -I/usr/include/SDL -W -o ../snake snake.c Game.c Window.o Snake.o Food.o -lSDL
#Window.o: 
#	gcc -I/usr/include/SDL -W -c Window.c -lSDL
#Game.o : Food.o Snake.o Window.o 
#	gcc -I/usr/include/SDL -W -c Game.c Snake.o Food.o Window.o -lSDL
#Snake.o: RectCollection.o
#	gcc -I/usr/include/SDL -W -c Snake.c RectCollection.o -lSDL
#Food.o:
#	gcc -I/usr/include/SDL -W -c Food.c -lSDL
#RectCollection.o:
#	gcc -I/usr/include/SDL -W -c RectCollection.c -lSDL
snake: Window.o Snake.o Game.o Food.o RectCollection.o
	gcc -I/usr/include/SDL -W -o ../snake snake.c Window.o Snake.o Game.o Food.o RectCollection.o -lSDL
Window.o:
	gcc -I/usr/include/SDL -W -c Window.c -lSDL
Snake.o:
	gcc -I/usr/include/SDL -W -c Snake.c -lSDL
Game.o :
	gcc -I/usr/include/SDL -W -c Game.c -lSDL
Food.o:
	gcc -I/usr/include/SDL -W -c Food.c -lSDL
RectCollection.o:
	gcc -I/usr/include/SSDL -W -c RectCollection.c -lSDL
