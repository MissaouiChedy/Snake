#ifndef _GAME
#define _GAME
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
typedef struct SNAKE Snake;
typedef struct FOOD Food;
struct GAME {
  Window *window;
  Snake *snake;
  Food *food;
};
typedef struct GAME Game;
Game *createGame(Window *);
void destroyGame(Game *) ;
int getGridSize(Game *);
int getXBound(Game *);
int getYBound(Game *);
int snakeEatFood(Game *);
void displayGame(Game *);
void handleEvent(Game *,SDL_Event );
int isInGrid(Game *,SDL_Rect );
int getCenteringFactor(Game *);
SDL_Rect centerPosition(Game *,SDL_Rect );
SDL_Rect deCenterPosition(Game *,SDL_Rect );
SDL_Rect getDecentredFoodPosition(Game *);
SDL_Rect generateFoodPosition(Game *) ;
void generateFood(Game *) ;
#endif
