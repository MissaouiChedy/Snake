#include <stdlib.h>
#include "SDL.h"
#include "Boolean.h"
#include "Position.h"
Position createPosition(int x, int y){
 Position valueInstance;
 valueInstance.x=x;
 valueInstance.y=y;
return valueInstance;
}

Boolean isEqualPositions(Position pos1, Position pos2){
 Boolean isEqualFlag = FALSE;
 if ( (pos1.x == pos2.x) && (pos1.y==pos2.y) ){
     isEqualFlag = TRUE; 
 }
return isEqualFlag;
}    
