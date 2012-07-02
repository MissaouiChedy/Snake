#ifndef _POSITION
#define _POSITION
#include "Boolean.h"
typedef SDL_Rect Position;

Position createPosition(int, int);
Boolean isEqualPositions(Position, Position);    
#endif
