#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "Window.h"
#include "Snake.h"
#include "Food.h"
int ScreenHeight=600;
int ScreenWidth=800;
void displaySnake_(Window *window,Snake worm){
  
}
int main(int argc ,char *argv){
 SDL_Init(SDL_INIT_VIDEO);
  Window frame = createWindow(ScreenWidth,ScreenHeight,"Snakeing!");
  //SDL_Surface *frame = SDL_SetVideoMode(ScreenWidth,ScreenHeight,16,SDL_HWSURFACE);
  Snake worm = createSnake(10);
  //Food food =createFood(5);
  SDL_Event event;
  //SDL_WM_SetCaption("Snaking!",NULL); 
  refreshWindow(&frame);
  //SDL_FillRect(frame,NULL,SDL_MapRGB(frame->format,255,255,255));
  displaySnake(frame.surface,worm);
  //displayFood(frame,food);
  flipWindow(&frame);
  //SDL_Flip(frame);
 int flag =1 ;
 while (flag){
  moveSnake(&worm);
  refreshWindow(&frame);
  
  //SDL_FillRect(frame,NULL,SDL_MapRGB(frame->format,255,255,255));
  //displayFood(frame,food);
  displaySnake(frame.surface,worm); 
  flipWindow(&frame);
  //SDL_Flip(frame);
  SDL_Delay(100);
  SDL_PollEvent(&event);
   
   if (event.type==SDL_QUIT){
      flag=0;
      break;
    }
   else if (event.type==SDL_KEYDOWN) {
     switch (event.key.keysym.sym){
     case SDLK_UP :setDirection(&worm,UP);break;
     case SDLK_DOWN :setDirection(&worm,DOWN); break;
     case SDLK_RIGHT :setDirection(&worm,RIGHT);  break;
     case SDLK_LEFT :setDirection(&worm,LEFT); break;
      }

   }
  
  } 
// destroyFood(food);
 destroySnake(worm);
 destroyWindow(frame); 
//SDL_FreeSurface(frame);
 SDL_Quit();
 return 0;
}

