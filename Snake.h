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
typedef struct SNAKE Snake;
Snake *createSnake(Game *,int ,int ) ;
void displaySnake(SDL_Surface *,Snake *);
void eat(Snake *);
Direction opposite(Direction );
void setDirection(Snake *,Direction );
void moveSnake(Snake *) ;
SDL_Rect getSnakeHead(Snake *);
int getSnakeLength(Snake *);
int collideWithSnake(Snake *,SDL_Rect );
void destroySnake(Snake *);
#endif 
