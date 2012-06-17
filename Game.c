#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Window.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
Game *createGame(Window *window){
  Game *instance=malloc(sizeof(Game));
  instance->window = window;
  instance->snake = createSnake(SNAKE_LENGTH,SNAKE_SIZE,getWidth(instance->window),getHeight(instance->window));
  instance->food = createFood(FOOD_SIZE);
  setFoodPosition(instance->food,generateFoodPosition(instance));
 return instance;
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
 return (game->window->width)-(getGridSize(game));
}
int getYBound(Game *game){
 return (game->window->height)-(getGridSize(game));
}
int snakeEatFood(Game *game){
  SDL_Rect _snake = getSnakeHead(game->snake);
  SDL_Rect _food = getDecentredFoodPosition(game);
return ((_snake.x==_food.x)&&(_snake.y==_food.y));
}
void displayGame(Game *game){
  moveSnake(game->snake);
  if (snakeEatFood(game)){
   generateFood(game);
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
int isInGrid(Game *game,SDL_Rect position){
 return  ( (position.x%getGridSize(game)==0)
            && (position.y%getGridSize(game)==0) );
   }
int getCenteringFactor(Game *game){
  return (getGridSize(game)/2)-(game->food->size/2) ;
}
SDL_Rect centerPosition(Game *game,SDL_Rect position){
  position.x+=getCenteringFactor(game);
  position.y+=getCenteringFactor(game);
  return position ;
 }
SDL_Rect deCenterPosition(Game *game,SDL_Rect position){
  position.x-=getCenteringFactor(game);
  position.y-=getCenteringFactor(game);
  return position ;
}
SDL_Rect getDecentredFoodPosition(Game *game){
  return deCenterPosition(game,game->food->position);
}
SDL_Rect generateFoodPosition(Game *game) {
   SDL_Rect temp;
   do {
      temp.x = (rand()%(getXBound(game)));
      temp.y = (rand()%(getYBound(game)));
     }
  while (!isInGrid(game,temp)&& !isInSnake(game->snake,temp) ) ; 
  temp=centerPosition(game,temp);
 return temp; 
}
void generateFood(Game *game) {
  setFoodPosition(game->food,generateFoodPosition(game));
  assert(!isInSnake(game->snake,getDecentredFoodPosition(game)));
}
