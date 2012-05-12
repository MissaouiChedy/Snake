#ifndef _FOOD
#define _FOOD
#include "SDL.h"
#include <stdlib.h>
#include <assert.h>
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
 int gridSize;
 int xBound;
 int yBound;
};
typedef struct FOOD Food;

Food *createFood(int size,int gridSize,int screenWidth,int screenHeight){
  Food *temp;
  temp=malloc(sizeof(Food));
  temp->size=size;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,temp->size,temp->size,16,0,0,0,0);
  temp->position.x=300;
  temp->position.y=300; 
  temp->gridSize=gridSize;
  temp->xBound=screenWidth-gridSize;
  temp->yBound=screenHeight-gridSize;
  return temp;
  }
void destroyFood(Food *food){
  SDL_FreeSurface(food->surface);
  food->surface=NULL; 
  free(food);
 }
void displayFood(SDL_Surface *dest,Food *food){
  SDL_BlitSurface(food->surface,NULL,dest,&(food->position));
  }
int isInGrid(Food *food){
 return  ( (food->position.x%food->gridSize==0)
            && (food->position.y%food->gridSize==0) );
   }
SDL_Rect centerPosition(Food *food){
  int opt= (food->gridSize/2)-(food->size/2);
  food->position.x+=opt;
  food->position.y+=opt;
  return food->position ;
  }
void regenFood(Food *food) {
  do {
      food->position.x = (rand()%( food->xBound    ));
      food->position.y = (rand()%( food->yBound   ));
  }
  while (!isInGrid(food)) ; 
  food->position=centerPosition(food);
}
#endif
