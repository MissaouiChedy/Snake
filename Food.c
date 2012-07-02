#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Boolean.h"
#include "Position.h"
#include "Food.h"
Food *createFood(int size, Position minBound, Position maxBound, int gridCellSize){
  Food *instance;
  instance = (Food *) malloc(sizeof(Food));
  instance->size = size;
  instance->surface = SDL_CreateRGBSurface(SDL_HWSURFACE,instance->size,instance->size,16,0,0,0,0); 
  instance->position = createPosition(0,0);
  instance->gridOriginPoint = minBound; 
  instance->gridBoundPoint = maxBound;
  instance->gridCellSize = gridCellSize;
  generateFood(instance);
  return instance;
}
void destroyFood(Food *food){
  SDL_FreeSurface(food->surface);
  food->surface = NULL; 
  free(food);
 }
void displayFood(SDL_Surface *dest,Food *food){
  SDL_BlitSurface(food->surface, NULL, dest, &(food->position));
  }
void setFoodPosition(Food *food, Position position){
  food->position=position;
}

Boolean isInGrid(Food *food, Position position){
 return ( (((position.x % food->gridCellSize) - food->gridOriginPoint.x) == 0 )
            && (((position.y % food->gridCellSize) - food->gridOriginPoint.y) == 0) );
}

Position generateFoodPosition(Food *food) {
   Position temp;
   do {
      temp.x = (rand()%(food->gridBoundPoint.x))+food->gridOriginPoint.x;
      temp.y = (rand()%(food->gridBoundPoint.y))+food->gridOriginPoint.y;
     }
  while (!isInGrid(food,temp)) ; 

 return temp; 
}
void generateFood(Food *food) {
  setFoodPosition(food,generateFoodPosition(food));
  /* Asserts that the generated point Doesn't get out of the game panel */	
  assert( food->position.x < ( food->gridBoundPoint.x + food->gridOriginPoint.x) );
  assert( food->position.y < ( food->gridBoundPoint.y + food->gridOriginPoint.y) );
}
int getFoodSize(Food *food){
 return food->size;
}
Position getFoodPosition(Food *food){
 return food->position;
}
