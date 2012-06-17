#ifndef _GAME
#define _GAME
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
typedef struct SNAKE Snake;
typedef struct FOOD Food;
typedef struct WINDOW Window;
struct GAME {
  Window *window;
  Snake *snake;
  Food *food;
};
typedef struct GAME Game;
Game *createGame(Window *);
void destroyGame(Game *) ;
/*PRIVATE*/
int getGridSize(Game *);
int getXBound(Game *);
int getYBound(Game *);
/* PRIVATE */
int snakeEatFood(Game *);

void displayGame(Game *);

void handleEvent(Game *,SDL_Event );
/* PRIVATE */
int isInGrid(Game *,SDL_Rect );
/*PRivate*/
int getCenteringFactor(Game *);
/* PRIVATE */
SDL_Rect centerPosition(Game *,SDL_Rect );
/* PRIVATE */
SDL_Rect deCenterPosition(Game *,SDL_Rect );
/* PRIVATE */
SDL_Rect getDecentredFoodPosition(Game *);
/*PRIVATE*/
SDL_Rect generateFoodPosition(Game *) ;
/* PRIVATE */
void generateFood(Game *) ;
#endif
