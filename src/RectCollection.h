#ifndef _RectCollection
#define _RectCollection
#include "Position.h"
typedef struct RECTCOLLECTION RectCollection;  
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
