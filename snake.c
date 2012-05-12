#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL.h"
#include "Window.h"
#include "Game.h"
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
/*void displayGame(Window *window,Snake *snake,Food *food){
  moveSnake(snake);
  refreshWindow(window);
  displaySnake(window->surface,snake); 
  displayFood(window->surface,food);
  flipWindow(window);
}*/
int main(int argc ,char *argv){
 SDL_Init(SDL_INIT_VIDEO);
  Window *frame = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Snakeing!");
  //GAme init
 /* Snake *worm = createSnake(SNAKE_LENGTH,SNAKE_SIZE,SCREEN_WIDTH,SCREEN_HEIGHT);
  Food *food = createFood(FOOD_SIZE,SNAKE_SIZE,SCREEN_WIDTH,SCREEN_HEIGHT);
 */
  Game *game=createGame(frame);
  SDL_Event event;
 int flag =1 ;
 while (flag){
  displayGame(game);  
  SDL_Delay(100);
  SDL_PollEvent(&event);
   
   if (event.type==SDL_QUIT){
      flag=0;
      break;
    }
   else if (event.type==SDL_KEYDOWN) {
    //handle event
    /*
    switch (event.key.keysym.sym){
     case SDLK_UP :setDirection(worm,UP);break;
     case SDLK_DOWN :setDirection(worm,DOWN);break;
     case SDLK_RIGHT :setDirection(worm,RIGHT);break;
     case SDLK_LEFT :setDirection(worm,LEFT);break;
     case SDLK_d :regenFood(food); 
      }
    */
     handleEvent(game,event); 
   }
  } 
 destroyGame(game); 
 game=NULL;
 destroyWindow(frame); 
 frame=NULL;
 SDL_Quit();
 return 0;
}

