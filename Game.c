#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Window.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
struct GAME *createGame(Window *window){
  struct GAME *temp=malloc(sizeof(Game));
  temp->window = window;
  temp->snake = createSnake(temp,SNAKE_LENGTH,SNAKE_SIZE);
  temp->food = createFood(FOOD_SIZE);
  setFoodPosition(temp->food,generateFoodPosition(temp));
 return temp;
}
void destroyGame(struct GAME *game) {
  destroyFood(game->food);
  game->food=NULL;
  destroySnake(game->snake);
  game->snake=NULL;
  game->window=NULL;
  free(game);
}
int getGridSize(struct GAME *game){
 return game->snake->size; 
}
int getXBound(struct GAME *game){
 return (game->window->width)-(getGridSize(game));
}
int getYBound(struct GAME *game){
 return (game->window->height)-(getGridSize(game));
}
int snakeEatFood(struct GAME *game){
  SDL_Rect _snake = getSnakeHead(game->snake);
  SDL_Rect _food = getDecentredFoodPosition(game);
return ((_snake.x==_food.x)&&(_snake.y==_food.y));
}
void displayGame(struct GAME *game){
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
void handleEvent(struct GAME *game,SDL_Event event){
   switch (event.key.keysym.sym){
     case SDLK_UP :setDirection(game->snake,UP);break;
     case SDLK_DOWN :setDirection(game->snake,DOWN);break;
     case SDLK_RIGHT :setDirection(game->snake,RIGHT);break;
     case SDLK_LEFT :setDirection(game->snake,LEFT);break;
    }
}
int isInGrid(struct GAME *game,SDL_Rect position){
 return  ( (position.x%getGridSize(game)==0)
            && (position.y%getGridSize(game)==0) );
   }
int getCenteringFactor(struct GAME *game){
  return (getGridSize(game)/2)-(game->food->size/2) ;
}
SDL_Rect centerPosition(struct GAME *game,SDL_Rect position){
  position.x+=getCenteringFactor(game);
  position.y+=getCenteringFactor(game);
  return position ;
 }
SDL_Rect deCenterPosition(struct GAME *game,SDL_Rect position){
  position.x-=getCenteringFactor(game);
  position.y-=getCenteringFactor(game);
  return position ;
}
SDL_Rect getDecentredFoodPosition(struct GAME *game){
  return deCenterPosition(game,game->food->position);
}
SDL_Rect generateFoodPosition(struct GAME *game) {
   SDL_Rect temp;
   do {
      temp.x = (rand()%(getXBound(game)));
      temp.y = (rand()%(getYBound(game)));
     }
  while (!isInGrid(game,temp)&& !collideWithSnake(game->snake,temp) ) ; 
  temp=centerPosition(game,temp);
 return temp; 
}
void generateFood(struct GAME *game) {
  setFoodPosition(game->food,generateFoodPosition(game));
  assert(!collideWithSnake(game->snake,getDecentredFoodPosition(game)));
}
