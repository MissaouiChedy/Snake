################################################################################################
# VARIABLES DEFINITION
################################################################################################
SDL_INCLUDE_PATH = /usr/include/SDL
WARNING_OPTIONS = -W -Wstrict-prototypes -ansi 
BUILD_PATH = ../
################################################################################################
# IMPLICITE RULES
################################################################################################
%.o: COMPILATION_OPTION = -c
%.o: %.c %.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) $(COMPILATION_OPTION) $<
################################################################################################
snake: Window.o Snake.o Food.o Game.o RectCollection.o Position.o
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -o $(BUILD_PATH)$@ snake.c $^ -lSDL

Window.o: Window.c Window.h
Snake.o: Snake.c Snake.h
Game.o: Game.c Game.h
Food.o: Food.c Food.h
RectCollection.o: RectCollection.c RectCollection.h
Position.o: Position.c Position.h
.PHONY: clean
clean: 	
	rm *.o
