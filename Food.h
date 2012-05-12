#ifndef _FOOD
#define _FOOD
#include "SDL.h"
#include <stdlib.h>
#include <assert.h>
//typedef struct GAME Game;
#include "Game.h"
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
 Game *game;
};
typedef struct FOOD Food;

Food *createFood(Game *game,int size){
  Food *temp;
  temp=malloc(sizeof(Food));
  temp->size=size;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,temp->size,temp->size,16,0,0,0,0);
  temp->position.x=300;
  temp->position.y=300; 
  temp->game=game;
  return temp;
  }
void destroyFood(Food *food){
  SDL_FreeSurface(food->surface);
  food->surface=NULL; 
  food->game=NULL;
  free(food);
 }
void displayFood(SDL_Surface *dest,Food *food){
  SDL_BlitSurface(food->surface,NULL,dest,&(food->position));
  }
int isInGrid(Food *food){
 return  ( (food->position.x%getGridSize(food->game)==0)
            && (food->position.y%getGridSize(food->game)==0) );
   }
SDL_Rect centerPosition(Food *food){
  int opt= (getGridSize(food->game)/2)-(food->size/2);
  food->position.x+=opt;
  food->position.y+=opt;
  return food->position ;
  }
void regenFood(Food *food) {
  do {
      food->position.x = (rand()%( getXBound(food->game)    ));
      food->position.y = (rand()%( getYBound(food->game)   ));
  }
  while (!isInGrid(food)) ; 
  food->position=centerPosition(food);
}
#endif
