#include <stdlib.h>
#include <stdio.h>
#include "SDL.h"
#include "Window.h"
#include "Snake.h"
#include "Food.h"
#define SNAKE_SIZE 10
#define SNAKE_LENGTH 14
#define FOOD_SIZE 6
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
int main(int argc ,char *argv){
 SDL_Init(SDL_INIT_VIDEO);
  Window frame = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Snakeing!");
  Snake worm = createSnake(SNAKE_LENGTH,SNAKE_SIZE,SCREEN_WIDTH,SCREEN_HEIGHT);
  Food food = createFood(FOOD_SIZE,SNAKE_SIZE,SCREEN_WIDTH,SCREEN_HEIGHT);
  SDL_Event event;
  refreshWindow(&frame);
  displaySnake(frame.surface,worm);
  flipWindow(&frame);
 int flag =1 ;
 while (flag){
  moveSnake(&worm);
  refreshWindow(&frame);
  displaySnake(frame.surface,worm); 
  displayFood(frame.surface,food);
  flipWindow(&frame);
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
     case SDLK_d :regenFood(&food); 
      }

   }
  
  } 
 destroyFood(food);
 destroySnake(worm);
 destroyWindow(frame); 
 SDL_Quit();
 return 0;
}

