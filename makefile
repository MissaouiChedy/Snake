SDL_INCLUDE_PATH = /usr/include/SDL
WARNING_OPTIONS = -W -Wstrict-prototypes -ansi 
snake: Window.o Snake.o Game.o Food.o RectCollection.o
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -o ../snake snake.c Window.o Snake.o Game.o Food.o RectCollection.o -lSDL
Window.o: Window.c Window.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -c Window.c -lSDL
Snake.o: Snake.c Snake.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -c Snake.c -lSDL
Game.o : Game.c Game.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -c Game.c -lSDL
Food.o: Food.c Food.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -c Food.c -lSDL
RectCollection.o: RectCollection.c RectCollection.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -c RectCollection.c -lSDL
.PHONY: clean
clean: 	
	rm *.o
