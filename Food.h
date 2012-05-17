#ifndef _FOOD
#define _FOOD
#include "SDL.h"
#include <stdlib.h>
#include <assert.h>
typedef struct GAME Game;
#include "Game.h"
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
};
typedef struct FOOD Food;
Food *createFood(int size){
  Food *temp;
  temp=malloc(sizeof(Food));
  temp->size=size;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,temp->size,temp->size,16,0,0,0,0); 
  temp->position.x=0;
  temp->position.y=0;
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
void setFoodPosition(Food *food,SDL_Rect position){
  food->position=position;
}
#endif
