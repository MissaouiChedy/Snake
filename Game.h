#ifndef _GAME
#define _GAME
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
typedef enum BOOLEAN Boolean;
typedef SDL_Rect Position;
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

static Boolean snakeEatFood(Game *);
static int getCenteringFactor(int ,int);
static Position deCenterPosition(Game *,Position );
static Position getDecentredFoodPosition(Game *game);
#endif
