#include <assert.h>
#include <stdio.h>
#include "SDL.h"
#include "Game.h"
#include "RectCollection.h"
#include "Snake.h"
Snake *createSnake(int length,int size,int XBound,int YBound) {
  Snake *instance = malloc(sizeof(Snake)) ;
  instance->surface =  SDL_CreateRGBSurface(SDL_HWSURFACE,size,size,16,0,0,0,0);
  instance->vect = createRectCollection(length);
  SDL_Rect initing = createRect(100,100);
  int i = 0;
  for (i = 0;i<instance->vect->length;i++){
     setRect(instance->vect,i,initing);
     initing.y-=size;
    }
  instance->direction = DOWN; 
  instance->XBound = XBound;
  instance->YBound = YBound;
  instance->size = size;
return instance;
}
void displaySnake(SDL_Surface *dest,Snake *snake){
  int i;
  for (i = 0;i<snake->vect->length;i++){
     SDL_BlitSurface(snake->surface,NULL,dest,getRect(snake->vect,i));
   }
}

void  eat(Snake *snake){
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
              getRect(snake->vect,0)->y -= snake->size;
              if (getRect(snake->vect,0)->y<0){
                getRect(snake->vect,0)->y = snake->YBound;
              }
              break;
    case DOWN :   
               getRect(snake->vect,0)->y += snake->size;
               if (getRect(snake->vect,0)->y>(snake->YBound)){
                 getRect(snake->vect,0)->y = 0;
               }
               break;
    case RIGHT : 
               getRect(snake->vect,0)->x += snake->size;
               if (getRect(snake->vect,0)->x>snake->XBound){
                 getRect(snake->vect,0)->x = 0;
               }
                break;
    case LEFT :  
               getRect(snake->vect,0)->x -= snake->size;
               if (getRect(snake->vect,0)->x<0){
                 getRect(snake->vect,0)->x = snake->XBound;
               }
                break;
    default : printf("Invalid DIRECTION At void moveSnake(Snake *snake);");   
   }
 
}
SDL_Rect getSnakeHead(Snake *snake){
  return *(getRect(snake->vect,0));
}
int getSnakeLength(Snake *snake){
 return snake->vect->length ;
}

int isInSnake(Snake *snake,SDL_Rect position){
 int i = 0;
 int flag = 0;
 for (i = 0;i<getSnakeLength(snake);i++){
    if( (getRect(snake->vect,i)->x==position.x)&&(getRect(snake->vect,i)->y==position.y)){
        flag = 1;
        break;    
       }
  }
 return flag;
}

void destroySnake(Snake *snake){
 SDL_FreeSurface(snake->surface);
 snake->surface = NULL;
 destroyRectCollection(snake->vect);
 free(snake);
}
