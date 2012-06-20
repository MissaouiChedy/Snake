#include <stdlib.h>
#include "SDL.h"
#include <assert.h>
#include "Window.h"

Window *createWindow(int width,int height,const char *title){
 Window *instance;
 instance = (Window *) malloc(sizeof(Window));
 instance->width =width;
 instance->height=height;
 instance->surface=SDL_SetVideoMode(instance->width,instance->height,16,SDL_HWSURFACE);
 SDL_WM_SetCaption(title,NULL);
 refreshWindow(instance);
 return instance;
}
void destroyWindow(Window *window) {
 SDL_FreeSurface(window->surface);
 window->surface=NULL;
 free(window);
}
int getWidth(Window *window){
  return window->width;
}
int getHeight(Window *window){
  return window->height;
}
void flipWindow(Window *window){
 SDL_Flip(window->surface);
}
void refreshWindow(Window *window){
 SDL_FillRect(window->surface,NULL,SDL_MapRGB(window->surface->format,255,255,255));
}
void addSurface(Window *window, SDL_Surface *surface){
  
}
