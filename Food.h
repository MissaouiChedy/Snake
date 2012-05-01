#ifndef _FOOD
#define _FOOD
#include "SDL.h"
#include <stdlib.h>
#include <assert.h>
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
};
typedef struct FOOD Food;

Food createFood(int size){
  Food temp;
  temp.size=size;
  temp.surface= SDL_CreateRGBSurface(SDL_HWSURFACE,temp.size,temp.size,16,0,0,0,0);
  temp.position.x=300;
  temp.position.y=300; 
  return temp;
  }
void destroyFood(Food food){
  SDL_FreeSurface(food.surface);
  }
void displayFood(SDL_Surface *dest,Food food){
  SDL_BlitSurface(food.surface,NULL,dest,&(food.position));
  }
int isInGrid(SDL_Rect position){
 return  ((position.x%SEGMENT==0)&&(position.y%SEGMENT==0));
   }
SDL_Rect centerPosition(Food food){
  int opt= (SEGMENT/2)-(food.size/2);
  food.position.x+=opt;
  food.position.y+=opt;
  return food.position ;
  }
void regenFood(Food *food) {
  extern ScreenWidth;
  extern ScreenHeight;
  do {
      food->position.x = (rand()%(ScreenWidth-SEGMENT));
      food->position.y = (rand()%(ScreenHeight-SEGMENT));
  }
  while (!isInGrid(food->position)) ; 
  food->position=centerPosition(*food);
}
#endif
