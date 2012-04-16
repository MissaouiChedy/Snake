#ifndef FOODING
#define FOODING
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
void regenFood(Food *food) {
  extern ScreenWidth;
  extern ScreenHeight;
  food->position.x = (SEGMENT/4)+(rand()%(ScreenWidth/SEGMENT));
  food->position.y = (SEGMENT/4)+(rand()%(ScreenHeight/SEGMENT));
 }
#endif
