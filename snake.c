#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SDL.h"
#include "Window.h"
#include "Game.h"
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800
int main(int argc ,char **argv){
 SDL_Init(SDL_INIT_VIDEO);
 Window *frame = createWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Snakeing!");
 struct GAME *game = createGame(frame);
 SDL_Event event;
 int flag = 1 ;
 while (flag){
   displayGame(game);  
   SDL_PollEvent(&event);
   SDL_Delay(80);
    if (event.type == SDL_QUIT){
       flag = 0;
       break;
      } 
     else if (event.type == SDL_KEYDOWN) {
        handleEvent(game,event); 
       }
  } 
 destroyGame(game); 
 game = NULL;
 destroyWindow(frame); 
 frame = NULL;
 SDL_Quit();
 return 0;
}
