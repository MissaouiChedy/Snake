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
void displayGame(Game *);
void handleEvent(Game *,SDL_Event );
/* PRIVATE */
int snakeEatFood(Game *);
/*PRivate*/
int getCenteringFactor(int ,int);
/* PRIVATE */
SDL_Rect deCenterPosition(Game *,SDL_Rect );
/* PRIVATE */
SDL_Rect getDecentredFoodPosition(Game *game);
#endif
