#ifndef _SNAKE
#define _SNAKE
#include "Boolean.h"
typedef enum DIRECTION Direction;
enum DIRECTION {
  UP =1,
  RIGHT=2,
  DOWN =3,
  LEFT=4
};
typedef struct GAME Game;
typedef struct RECTCOLLECTION RectCollection;

struct SNAKE {
   SDL_Surface *surface;
   RectCollection *vect;  
   Direction direction;  
   Position gridOriginPoint;
   Position gridBoundPoint;
   int size;
}; 
typedef struct SNAKE Snake;
Snake *createSnake(int ,int ,Position ,Position) ;
void destroySnake(Snake *);
void displaySnake(SDL_Surface *,Snake *);
void eat(Snake *);
void setDirection(Snake *,Direction );
void moveSnake(Snake *) ;
Position *getSnakeHead(Snake *);
Boolean isInSnake(Snake *,Position );
Boolean isSnakeHitHimself(Snake *);
int getSnakeSize(Snake *);

static int getSnakeLength(Snake *);
static Direction opposite(Direction );
#endif 
