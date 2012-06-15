#ifndef _RectCollection
#define _RectCollection
typedef struct RECTCOLLECTION RectCollection;  
struct RECTCOLLECTION{
  SDL_Rect *vector;
  int length;
};
SDL_Rect createRect(int ,int );
RectCollection *createRectCollection(int );
void destroyRectCollection(RectCollection *);
SDL_Rect *getRect(RectCollection *,int );
void setRect(RectCollection *,int ,SDL_Rect );
void shiftRight(RectCollection *);
void addRect(RectCollection *,SDL_Rect );
#endif
