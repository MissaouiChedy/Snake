#include <assert.h>
#include <stdio.h>
#include "SDL.h"
#include "Boolean.h"
#include "Position.h"
#include "Game.h"
#include "RectCollection.h"
#include "Snake.h"
Snake *createSnake(int length,int size,int XBound,int YBound) {
  Snake *instance = (Snake *) malloc(sizeof(Snake)) ;
  instance->surface =  SDL_CreateRGBSurface(SDL_HWSURFACE,size,size,16,0,0,0,0);
  instance->vect = createRectCollection(length);
  Position initing; 
         initing = createPosition(100,100);
  int i = 0;
  for (i = 0;i<instance->vect->length;i++){
     setRect(instance->vect,i,initing);
     initing.y-=size;
    }
  instance->direction = DOWN; 
  instance->XBound = XBound - size;
  instance->YBound = YBound - size;
  instance->size = size;
return instance;
}
void displaySnake(SDL_Surface *dest,Snake *snake){
  int i;
  for (i = 0;i<snake->vect->length;i++){
     SDL_BlitSurface(snake->surface,NULL,dest,getRect(snake->vect,i));
   }
}
void eat(Snake *snake){
  addRect( snake->vect,
                    *getRect(snake->vect,getSnakeLength(snake)-1));
}
Direction opposite(Direction direction){
  switch (direction){
    case UP : return DOWN;
    case DOWN : return UP;
    case RIGHT: return LEFT;
    case LEFT :return RIGHT;
   default : printf("Error bad direction at Direction opposite(Direction);");
   }
}
void setDirection(Snake *snake,Direction direction){
  assert((direction==UP)||(direction==DOWN)||(direction==RIGHT)||(direction==LEFT));
    if (direction!=opposite(snake->direction)) { 
      snake->direction = direction;
     }
} 
void moveSnake(Snake *snake) {
   shiftRight(snake->vect);
   switch (snake->direction) {
    case UP :   
              getSnakeHead(snake)->y -= snake->size;
              if (getSnakeHead(snake)->y<0){
                getSnakeHead(snake)->y = snake->YBound;
              }
              break;
    case DOWN :   
               getSnakeHead(snake)->y += snake->size;
               if (getSnakeHead(snake)->y>(snake->YBound)){
                 getSnakeHead(snake)->y = 0;
               }
               break;
    case RIGHT : 
               getSnakeHead(snake)->x += snake->size;
               if (getSnakeHead(snake)->x>snake->XBound){
                 getSnakeHead(snake)->x = 0;
               }
                break;
    case LEFT :  
               getSnakeHead(snake)->x -= snake->size;
               if (getSnakeHead(snake)->x<0){
                 getSnakeHead(snake)->x = snake->XBound;
               }
                break;
    default : printf("Invalid DIRECTION At void moveSnake(Snake *snake);");   
   }
}
Position *getSnakeHead(Snake *snake){
  return getRect(snake->vect,0);
}
int getSnakeLength(Snake *snake){
 return snake->vect->length ;
}

Boolean isInSnake(Snake *snake,Position position){
 int i = 0;
 Boolean isInSnakeFlag = FALSE;
 for (i = 0;i<getSnakeLength(snake);i++){
     if( isEqualPositions( *getRect(snake->vect,i),position) ){
        isInSnakeFlag = TRUE;
        break;    
       }
  }
 return isInSnakeFlag;
}

void destroySnake(Snake *snake){
 SDL_FreeSurface(snake->surface);
 snake->surface = NULL;
 destroyRectCollection(snake->vect);
 free(snake);
}
int getSnakeSize(Snake *snake){
 return snake->size;
}
