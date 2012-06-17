#ifndef _SNAKE
#define _SNAKE
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
   int XBound;
   int YBound;
   int size;
}; 
typedef struct SNAKE Snake;
Snake *createSnake(int ,int ,int ,int) ;
void destroySnake(Snake *);
void displaySnake(SDL_Surface *,Snake *);
void eat(Snake *);
/*PRIVATE*/
Direction opposite(Direction );

void setDirection(Snake *,Direction );

void moveSnake(Snake *) ;

SDL_Rect getSnakeHead(Snake *);
/*PRIVATE*/
int getSnakeLength(Snake *);
int isInSnake(Snake *,SDL_Rect );
#endif 
