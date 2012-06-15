#ifndef _FOOD
#define _FOOD
struct FOOD {
 SDL_Surface *surface;
 int size;
 SDL_Rect position;
};
struct FOOD *createFood(int );
void destroyFood(struct FOOD *);
void displayFood(SDL_Surface *,struct FOOD *);
void setFoodPosition(struct FOOD *,SDL_Rect );
#endif
