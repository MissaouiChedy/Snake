#ifndef _SNAKE
#define _SNAKE
typedef enum DIRECTION Direction;
enum DIRECTION {
  UP =1,
  RIGHT=2,
  DOWN =3,
  LEFT=4
};
typedef enum BOOLEAN Boolean;
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
void setDirection(Snake *,Direction );
void moveSnake(Snake *) ;
Position *getSnakeHead(Snake *);
Boolean isInSnake(Snake *,Position );
int getSnakeSize(Snake *);

static int getSnakeLength(Snake *);
static Direction opposite(Direction );
#endif 
