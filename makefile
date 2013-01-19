################################################################################################
# VARIABLES DEFINITION
################################################################################################
SDL_INCLUDE_PATH = /usr/include/SDL
WARNING_OPTIONS = -W -Wstrict-prototypes -ansi
BUILD_PATH = ./bin/
SOURCE_PATH = ./src/
################################################################################################
# IMPLICITE RULES
################################################################################################
%.o: COMPILATION_OPTION = -c
$(BUILD_PATH)%.o: $(SOURCE_PATH)%.c $(SOURCE_PATH)%.h
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) $(COMPILATION_OPTION) -o $@ $<
################################################################################################
run: snake.out
	./bin/$<
snake.out: $(BUILD_PATH)Window.o $(BUILD_PATH)Snake.o $(BUILD_PATH)Food.o $(BUILD_PATH)Game.o $(BUILD_PATH)RectCollection.o $(BUILD_PATH)Position.o
	gcc -I$(SDL_INCLUDE_PATH) $(WARNING_OPTIONS) -o $(BUILD_PATH)$@.out $(SOURCE_PATH)snake.c $^ -lSDL

$(BUILD_PATH)Window.o: $(SOURCE_PATH)Window.c $(SOURCE_PATH)Window.h
$(BUILD_PATH)Snake.o: $(SOURCE_PATH)Snake.c $(SOURCE_PATH)Snake.h
$(BUILD_PATH)Game.o: $(SOURCE_PATH)Game.c $(SOURCE_PATH)Game.h
$(BUILD_PATH)Food.o: $(SOURCE_PATH)Food.c $(SOURCE_PATH)Food.h
$(BUILD_PATH)RectCollection.o: $(SOURCE_PATH)RectCollection.c $(SOURCE_PATH)RectCollection.h
$(BUILD_PATH)Position.o: $(SOURCE_PATH)Position.c $(SOURCE_PATH)Position.h
.PHONY: clean
clean:
	rm $(BUILD_PATH)*.o
