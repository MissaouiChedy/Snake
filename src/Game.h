#ifndef _GAME
#define _GAME
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
#define SCORE_INCREMENT 5
#define GAME_PANEL_ORIGIN_PNT 0
#include "Boolean.h"
#include "Position.h"
typedef struct SNAKE Snake;
typedef struct FOOD Food;
typedef struct WINDOW Window;
struct GAME {
  Window *window;
  Snake *snake;
  Food *food;
  int score;
};
typedef struct GAME Game;
Game *createGame(Window *);
void destroyGame(Game *);
int getGameScore(Game *);
Boolean displayGame(Game *);
void handleEvent(Game *,SDL_Event );

static void incrementScore(Game *);
static Boolean runGame(Game *);
static Boolean snakeEatFood(Game *);
static int getCenteringFactor(int ,int);
static Position deCenterPosition(Game *,Position );
static Position getDecentredFoodPosition(Game *game);
#endif
