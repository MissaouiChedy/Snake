#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "RectCollection.h"
SDL_Rect createRect(int x,int y){
  SDL_Rect temp ;
  temp.x=x;
  temp.y=y;
 return temp;
}
RectCollection *createRectCollection(int length){
        RectCollection *instance;
        instance = (RectCollection *) malloc(sizeof(RectCollection));
        instance->length = length;
        instance->vector = (SDL_Rect *) malloc(sizeof(SDL_Rect)*instance->length);
        int i=0;
        for (i=0;i<instance->length;i++){
          (instance->vector+i)->x=0;
          (instance->vector+i)->y=0;
       }
   return instance;
}
void destroyRectCollection(RectCollection *vect){
  free(vect->vector);
  vect->vector=NULL;
  free(vect);
}
SDL_Rect *getRect(RectCollection *vect,int pos){
   assert((pos<vect->length)&&(pos>=0));
   return (vect->vector+pos);
}
void setRect(RectCollection *vect,int pos,SDL_Rect newValue){
  assert((pos<vect->length)&&(pos>=0));
 (vect->vector+(pos))->x= newValue.x ;
 (vect->vector+(pos))->y= newValue.y ;
}
void shiftRight(RectCollection *vect) {
  int i ;
   for (i=vect->length-1;i>0;i--){
    setRect(vect ,i ,*( getRect(vect,i-1)));
    }  
  }
void addRect(RectCollection *vect,SDL_Rect node){
 vect->vector= realloc(vect->vector,(vect->length+1)*sizeof(SDL_Rect));
 vect->length+=1; 
 setRect(vect,vect->length-1,node);
}
