#include <stdio.h>
#include "RectCollection.h"
#include <assert.h>



int main (int argc,char *argv[]){
  Rect_Collection vect = createRectCollection(4);
  addRect(&vect,createRect(10,10));  
  int i=0;
  for (i=0;i<vect.length;i++){
    printf("X : %d  Y : %d \n",getRect(vect,i)->x,getRect(vect,i)->y);
  }
  assert(vect.length==5);
  assert(getRect(vect,vect.length-1)->x==10);
  destroyRectCollection(vect);  

 printf("OK !\n");

return 0;
}
