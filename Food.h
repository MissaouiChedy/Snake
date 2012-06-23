#ifndef _FOOD
#define _FOOD
#include "Boolean.h"
#include "Position.h"
struct FOOD {
 SDL_Surface *surface;
 int size;
 Position position;
 Position gridOriginPoint;
 Position gridBoundPoint;
 int gridCellSize;
};
typedef struct FOOD Food;
Food *createFood(int ,int ,int ,int ,int);
void destroyFood(Food *);
void displayFood(SDL_Surface *,Food *);
void setFoodPosition(Food *,Position );
int getFoodSize(Food *);
Position getFoodPosition(Food *);
void generateFood(Food *) ;
static Boolean isInGrid(Food *,Position );
static Position generateFoodPosition(Food *) ;
#endif
