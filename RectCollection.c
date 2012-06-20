#include <stdlib.h>
#include <assert.h>
#include "SDL.h"
#include "Position.h"
#include "RectCollection.h"
RectCollection *createRectCollection(int length){
        RectCollection *instance;
        instance = (RectCollection *) malloc(sizeof(RectCollection));
        instance->length = length;
        instance->vector = (Position *) malloc(sizeof(Position)*instance->length);
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
Position *getRect(RectCollection *vect,int pos){
   assert((pos<vect->length)&&(pos>=0));
   return (vect->vector+pos);
}
void setRect(RectCollection *vect,int pos,Position newValue){
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
void addRect(RectCollection *vect,Position node){
 vect->vector= realloc(vect->vector,(vect->length+1)*sizeof(Position));
 vect->length+=1; 
 setRect(vect,vect->length-1,node);
}
