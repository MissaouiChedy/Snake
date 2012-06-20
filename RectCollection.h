#ifndef _RectCollection
#define _RectCollection
typedef struct RECTCOLLECTION RectCollection;  
typedef SDL_Rect Position;
struct RECTCOLLECTION{
  Position *vector;
  int length;
};
Position createRect(int ,int );
RectCollection *createRectCollection(int );
void destroyRectCollection(RectCollection *);
Position *getRect(RectCollection *,int );
void setRect(RectCollection *,int ,Position );
void shiftRight(RectCollection *);
void addRect(RectCollection *,Position );
#endif
