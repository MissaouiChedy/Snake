#ifndef Rect_Collection
#define Rect_Collection
typedef struct RECTCONTAINER{
  SDL_Rect *vector;
  int length;
} RectCollection;
  
SDL_Rect createRect(int ,int );
RectCollection *createRectCollection(int );
void destroyRectCollection(RectCollection *);
SDL_Rect *getRect(RectCollection *,int );
void setRect(RectCollection *,int ,SDL_Rect );
void shiftRight(RectCollection *);
void addRect(RectCollection *,SDL_Rect );
#endif
