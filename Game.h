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
struct GAME *createGame(Window *);
void destroyGame(struct GAME *) ;
int getGridSize(struct GAME *);
int getXBound(struct GAME *);
int getYBound(struct GAME *);
int snakeEatFood(struct GAME *);
void displayGame(struct GAME *);
void handleEvent(struct GAME *,SDL_Event );
int isInGrid(struct GAME *,SDL_Rect );
int getCenteringFactor(struct GAME *);
SDL_Rect centerPosition(struct GAME *,SDL_Rect );
SDL_Rect deCenterPosition(struct GAME *,SDL_Rect );
SDL_Rect getDecentredFoodPosition(struct GAME *);
SDL_Rect generateFoodPosition(struct GAME *) ;
void generateFood(struct GAME *) ;
#endif
