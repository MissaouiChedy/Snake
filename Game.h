#ifndef _GAME
#define _GAME
#include "SDL.h"
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
#include "Window.h"
typedef struct SNAKE Snake;
#include "Snake.h"
typedef struct FOOD Food;
#include "Food.h"
struct GAME {
  Window *window;
  Snake *snake;
  Food *food;
};
Game *createGame(Window *window){
  Game *temp=malloc(sizeof(Game));
  temp->window = window;
  temp->snake = createSnake(temp,SNAKE_LENGTH,SNAKE_SIZE);
  temp->food = createFood(temp,FOOD_SIZE);
 return temp;
}
void destroyGame(Game *game) {
  destroyFood(game->food);
  game->food=NULL;
  destroySnake(game->snake);
  game->snake=NULL;
  game->window=NULL;
  free(game);
}
int getGridSize(Game *game){
 return game->snake->size; 
}
int getXBound(Game *game){
 return (game->window->width) -(getGridSize(game));
}
int getYBound(Game *game){
 return (game->window->height) -(getGridSize(game));
}
void displayGame(Game *game){
  moveSnake(game->snake);
  refreshWindow(game->window);
  displaySnake(game->window->surface,game->snake); 
  displayFood(game->window->surface,game->food);
  flipWindow(game->window);
}
void handleEvent(Game *game,SDL_Event event){
   switch (event.key.keysym.sym){
     case SDLK_UP :setDirection(game->snake,UP);break;
     case SDLK_DOWN :setDirection(game->snake,DOWN);break;
     case SDLK_RIGHT :setDirection(game->snake,RIGHT);break;
     case SDLK_LEFT :setDirection(game->snake,LEFT);break;
     case SDLK_d :regenFood(game->food); 
    }
}
#endif
