#ifndef _FOOD
#define _FOOD
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
};
typedef struct FOOD Food;
Food *createFood(int );
void destroyFood(Food *);
void displayFood(SDL_Surface *,Food *);
void setFoodPosition(Food *,SDL_Rect );
#endif
