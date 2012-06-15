#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Food.h"
struct FOOD *createFood(int size){
  struct FOOD *temp;
  temp=malloc(sizeof(struct FOOD));
  temp->size=size;
  temp->surface= SDL_CreateRGBSurface(SDL_HWSURFACE,temp->size,temp->size,16,0,0,0,0); 
  temp->position.x=0;
  temp->position.y=0;
  return temp;
  }
void destroyFood(struct FOOD *food){
  SDL_FreeSurface(food->surface);
  food->surface=NULL; 
  free(food);
 }
void displayFood(SDL_Surface *dest,struct FOOD *food){
  SDL_BlitSurface(food->surface,NULL,dest,&(food->position));
  }
void setFoodPosition(struct FOOD *food,SDL_Rect position){
  food->position=position;
}
