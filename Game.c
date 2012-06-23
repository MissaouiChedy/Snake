#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Boolean.h"
#include "Position.h"
#include "Window.h"
#include "Food.h"
#include "Snake.h"
#include "Game.h"
#define SCORE_INCREMENT 5
Game *createGame(Window *window){
  Game *instance = (Game *) malloc(sizeof(Game));
  instance->window = window;
  instance->snake = createSnake(SNAKE_LENGTH,SNAKE_SIZE,
                                   getWidth(instance->window),getHeight(instance->window));
  instance->food = createFood(FOOD_SIZE,getCenteringFactor(SNAKE_SIZE,FOOD_SIZE),
                                getWidth(instance->window),getHeight(instance->window),SNAKE_SIZE);
  instance->score = 0;
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
int getGameScore(Game *game){
 return game->score;
}
Boolean snakeEatFood(Game *game){
  Position snakePos = *( getSnakeHead(game->snake) );
  Position foodPos = getDecentredFoodPosition(game);
return ( isEqualPositions(snakePos,foodPos) );
}
Boolean displayGame(Game *game){
  
  if ( runGame(game) ){
     refreshWindow(game->window);
     displaySnake(game->window->surface,game->snake); 
     displayFood(game->window->surface,game->food);
     flipWindow(game->window);
   return TRUE;
    }
   else { 
        return FALSE;
     }  
}
static Boolean runGame(Game *game){
  Boolean isGameRunning = TRUE; 
  moveSnake(game->snake);
  if (isSnakeHitHimself(game->snake)){
     isGameRunning = FALSE;
   }
  if (snakeEatFood(game)){
   
   do {
     generateFood( game->food );
   } while (isInSnake( game->snake, getDecentredFoodPosition(game) ));
   incrementScore(game);
   eat(game->snake);
  }
return isGameRunning;
}
static void incrementScore(Game *game){
 game->score += SCORE_INCREMENT;
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
Position deCenterPosition(Game *game,Position position){
   position.x-=getCenteringFactor(getSnakeSize(game->snake),getFoodSize(game->food));
   position.y-=getCenteringFactor(getSnakeSize(game->snake),getFoodSize(game->food));
  return position ;
}
Position getDecentredFoodPosition(Game *game){
 return deCenterPosition(game, getFoodPosition(game->food));
}
