#ifndef _SNAKE
#define _SNAKE
#include "RectCollection.h"
typedef enum DIRECTION Direction;
enum DIRECTION {
  UP =1,
  RIGHT=2,
  DOWN =3,
  LEFT=4
};
typedef struct GAME Game;
struct SNAKE {
   SDL_Surface *surface;
   RectCollection *vect;  
   Direction direction;  
   Game *game;
   int size;
};
struct SNAKE *createSnake(Game *,int ,int ) ;
void displaySnake(SDL_Surface *,struct SNAKE *);
void eat(struct SNAKE *);
Direction opposite(Direction );
void setDirection(struct SNAKE *,Direction );
void moveSnake(struct SNAKE *) ;
SDL_Rect getSnakeHead(struct SNAKE *);
int getSnakeLength(struct SNAKE *);
int collideWithSnake(struct SNAKE *,SDL_Rect );
void destroySnake(struct SNAKE *);
#endif 
