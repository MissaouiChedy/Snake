#ifndef _SNAKE
#define _SNAKE
#include "SDL.h"
#include "RectCollection.h"
#include <assert.h>
#include <stdio.h>
#define SEGMENT 10
enum DIRECTION {
UP =1,
RIGHT=2,
DOWN =3,
LEFT=4
};
typedef enum DIRECTION Direction;
struct SNAKE {
  SDL_Surface *surface;
  RectCollection vect;  
  Direction direction;  
  
  };
typedef struct SNAKE Snake;

Snake createSnake(int length) ;

void displaySnake(SDL_Surface *dest,Snake snake);

void  eat(Snake *snake);

Direction opposite(Direction direction);

void setDirection(Snake *snake,int direction);

void moveSnake(Snake *snake) ;

void destroySnake(Snake snake);

Snake createSnake(int length) {
  int i;
  Snake temp ;
  temp.surface= SDL_CreateRGBSurface(SDL_HWSURFACE,SEGMENT,SEGMENT,16,0,0,0,0);
  temp.vect = createRectCollection(length);
  SDL_Rect initing = createRect(100,100);
  for (i=0;i<temp.vect.length;i++){
     setRect(&(temp.vect),i,initing);
     initing.y-=SEGMENT;
    }
  temp.direction=DOWN; 
 return temp;
}

void displaySnake(SDL_Surface *dest,Snake snake){
  int i;
  for (i=0;i<snake.vect.length;i++){
     
     SDL_BlitSurface(snake.surface,NULL,dest,getRect(snake.vect,i));
     
   }
}

void  eat(Snake *snake){
 SDL_Rect *newRect ; 
 newRect=getRect(snake->vect,snake->vect.length-1);
 newRect->x-=SEGMENT;
 newRect->y-=SEGMENT; 
 addRect(&(snake->vect),*newRect);
}
Direction opposite(Direction direction){
  switch (direction){
   case UP : return DOWN;
   case DOWN : return UP;
   case RIGHT: return LEFT;
   case LEFT :return RIGHT;
   default : printf("error bad direction at Direction opposite(Direction);");
   }
}
void setDirection(Snake *snake,int direction){
  assert((direction==UP)||(direction==DOWN)||(direction==RIGHT)||(direction==LEFT));
    if (direction!=opposite(snake->direction)) { 
      snake->direction=direction;
     }
} 
 void moveSnake(Snake *snake) {
   extern ScreenHeight;
   extern ScreenWidth;
   shiftRight(&(snake->vect));
   switch (snake->direction) {
    case UP :   
              getRect(snake->vect,0)->y-=SEGMENT;
              if (getRect(snake->vect,0)->y<0){
               getRect(snake->vect,0)->y=ScreenHeight-SEGMENT;
               }
              break;
    case DOWN :   
               getRect(snake->vect,0)->y+=SEGMENT;
               if (getRect(snake->vect,0)->y>=ScreenHeight){
               getRect(snake->vect,0)->y=0;
                }
               break;
    case RIGHT : 
                getRect(snake->vect,0)->x+=SEGMENT;
               if (getRect(snake->vect,0)->x>=ScreenWidth){
               getRect(snake->vect,0)->x=0;
                }
                break;
    case LEFT :  
                getRect(snake->vect,0)->x-=SEGMENT;
               if (getRect(snake->vect,0)->x<0){
               getRect(snake->vect,0)->x=ScreenWidth-SEGMENT;
                }
                break;
    default : printf("Invalid DIRECTION At void moveSnake(Snake *snake); ");exit(-1);   
   }
 
}

void destroySnake(Snake snake){
 SDL_FreeSurface(snake.surface);
 snake.surface=NULL;
 destroyRectCollection(snake.vect);
}
#endif 
