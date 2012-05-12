#ifndef _SNAKE
#define _SNAKE
#include "SDL.h"
#include "RectCollection.h"
#include <assert.h>
#include <stdio.h>
enum DIRECTION {
UP =1,
RIGHT=2,
DOWN =3,
LEFT=4
};
typedef enum DIRECTION Direction;
struct SNAKE {
  SDL_Surface *surface;
  RectCollection *vect;  
  Direction direction;  
  int size;
  int xBound;
  int yBound;
};
typedef struct SNAKE Snake;
Snake *createSnake(int length,int size,int screenWidth,int screenHeight) {
  int i;
  Snake *temp=malloc(sizeof(Snake)) ;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,size,size,16,0,0,0,0);
  temp->vect = createRectCollection(length);
  SDL_Rect initing = createRect(100,100);
  for (i=0;i<temp->vect->length;i++){
     setRect(temp->vect,i,initing);
     initing.y-=size;
    }
  temp->direction=DOWN; 
  temp->size=size;
  temp->xBound = screenWidth - size;
  temp->yBound = screenHeight -size ; 
return temp;
}

void displaySnake(SDL_Surface *dest,Snake *snake){
  int i;
  for (i=0;i<snake->vect->length;i++){
     
     SDL_BlitSurface(snake->surface,NULL,dest,getRect(snake->vect,i));
     
   }
}

void  eat(Snake *snake){
 SDL_Rect *newRect ; 
 newRect=getRect(snake->vect,snake->vect->length-1);
 newRect->x-=snake->size;
 newRect->y-=snake->size; 
 addRect(snake->vect,*newRect);
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
void setDirection(Snake *snake,int direction){
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
                getRect(snake->vect,0)->y=snake->yBound;
              }
              break;
    case DOWN :   
               getRect(snake->vect,0)->y+=snake->size;
               if (getRect(snake->vect,0)->y>snake->yBound){
                 getRect(snake->vect,0)->y=0;
               }
               break;
    case RIGHT : 
               getRect(snake->vect,0)->x+=snake->size;
               if (getRect(snake->vect,0)->x>snake->xBound){
                 getRect(snake->vect,0)->x=0;
               }
                break;
    case LEFT :  
               getRect(snake->vect,0)->x-=snake->size;
               if (getRect(snake->vect,0)->x<0){
                 getRect(snake->vect,0)->x=snake->xBound;
               }
                break;
    default : printf("Invalid DIRECTION At void moveSnake(Snake *snake); ");   
   }
 
}

void destroySnake(Snake *snake){
 SDL_FreeSurface(snake->surface);
 snake->surface=NULL;
 destroyRectCollection(snake->vect);
 free(snake);
}
#endif 
