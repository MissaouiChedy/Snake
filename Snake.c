#include <assert.h>
#include <stdio.h>
#include "SDL.h"
#include "Game.h"
#include "RectCollection.h"
#include "Snake.h"
Snake *createSnake(Game *game,int length,int size) {
  Snake *temp=malloc(sizeof(Snake)) ;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,size,size,16,0,0,0,0);
  temp->vect = createRectCollection(length);
  SDL_Rect initing = createRect(100,100);
  int i;
  for (i=0;i<temp->vect->length;i++){
     setRect(temp->vect,i,initing);
     initing.y-=size;
    }
  temp->direction=DOWN; 
  temp->game=game;
  temp->size=size;
return temp;
}
void displaySnake(SDL_Surface *dest,Snake *snake){
  int i;
  for (i=0;i<snake->vect->length;i++){
     SDL_BlitSurface(snake->surface,NULL,dest,getRect(snake->vect,i));
   }
}

void  eat(Snake *snake){
  addRect( snake->vect,
                    *getRect(snake->vect,snake->vect->length-1));
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
      snake->direction=direction;
     }
} 
void moveSnake(Snake *snake) {
   shiftRight(snake->vect);
   switch (snake->direction) {
    case UP :   
              getRect(snake->vect,0)->y-=snake->size;
              if (getRect(snake->vect,0)->y<0){
                getRect(snake->vect,0)->y=getYBound(snake->game);
              }
              break;
    case DOWN :   
               getRect(snake->vect,0)->y+=snake->size;
               if (getRect(snake->vect,0)->y>getYBound(snake->game)){
                 getRect(snake->vect,0)->y=0;
               }
               break;
    case RIGHT : 
               getRect(snake->vect,0)->x+=snake->size;
               if (getRect(snake->vect,0)->x>getXBound(snake->game)){
                 getRect(snake->vect,0)->x=0;
               }
                break;
    case LEFT :  
               getRect(snake->vect,0)->x-=snake->size;
               if (getRect(snake->vect,0)->x<0){
                 getRect(snake->vect,0)->x=getXBound(snake->game);
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

int collideWithSnake(Snake *snake,SDL_Rect position){
 int i=0;
 int flag=0;
 for (i=0;i<getSnakeLength(snake);i++){
    if( (getRect(snake->vect,i)->x==position.x)&&(getRect(snake->vect,i)->y==position.y)){
        flag=1;
        break;    
       }
  }
 return flag;
}

void destroySnake(Snake *snake){
 SDL_FreeSurface(snake->surface);
 snake->surface=NULL;
 snake->game=NULL;
 destroyRectCollection(snake->vect);
 free(snake);
}
