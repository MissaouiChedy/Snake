#ifndef _FOOD
#define _FOOD
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
 SDL_Rect gridOriginPoint;
 SDL_Rect gridBoundPoint;
 int gridCellSize;
};
typedef struct FOOD Food;
Food *createFood(int ,int ,int ,int ,int);
void destroyFood(Food *);
void displayFood(SDL_Surface *,Food *);
void setFoodPosition(Food *,SDL_Rect );
/* PRIVATE */
int isInGrid(Food *,SDL_Rect );
/*PRIVATE*/
SDL_Rect generateFoodPosition(Food *) ;
/* PRIVATE */
void generateFood(Food *) ;
#endif
