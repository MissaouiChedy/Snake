#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Window.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
Game *createGame(Window *window){
  Game *instance = malloc(sizeof(Game));
  instance->window = window;
  instance->snake = createSnake(SNAKE_LENGTH,SNAKE_SIZE,
                                   getWidth(instance->window),getHeight(instance->window));
  instance->food = createFood(FOOD_SIZE,getCenteringFactor(SNAKE_SIZE,FOOD_SIZE),
                                getWidth(instance->window),getHeight(instance->window),SNAKE_SIZE);
 return instance;
}
void destroyGame(Game *game) {
  destroyFood(game->food);
  game->food = NULL;
  destroySnake(game->snake);
  game->snake = NULL;
  game->window = NULL;
  free(game);
}

int snakeEatFood(Game *game){
  SDL_Rect _snake = *( getSnakeHead(game->snake) );
  SDL_Rect _food = getDecentredFoodPosition(game);
return ((_snake.x==_food.x)&&(_snake.y==_food.y));
}
void displayGame(Game *game){
  moveSnake(game->snake);
  if (snakeEatFood(game)){
   do {
   generateFood( game->food );
   } while(isInSnake( game->snake, getDecentredFoodPosition(game) ));
   eat(game->snake);
     }
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
    }
}
int getCenteringFactor(int snakeSize,int foodSize){
  return (snakeSize/2)-(foodSize/2);
}
SDL_Rect deCenterPosition(Game *game,SDL_Rect position){
  position.x-=getCenteringFactor(game->snake->size,game->food->size);
  position.y-=getCenteringFactor(game->snake->size,game->food->size);
  return position ;
}
SDL_Rect getDecentredFoodPosition(Game *game){
 return deCenterPosition(game, game->food->position);
}
