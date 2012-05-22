#include <stdlib.h>
#include "SDL.h"
#include <assert.h>
#include "Window.h"

Window *createWindow(int width,int height,const char *title){
 Window *ret;
 ret= malloc(sizeof(Window));
 ret->width =width;
 ret->height=height;
 ret->surface=SDL_SetVideoMode(ret->width,ret->height,16,SDL_HWSURFACE);
 SDL_WM_SetCaption(title,NULL);
 refreshWindow(ret);
 return ret;
}
void destroyWindow(Window *window) {
 SDL_FreeSurface(window->surface);
 window->surface=NULL;
 free(window);
}
void flipWindow(Window *window){
 SDL_Flip(window->surface);
}
void refreshWindow(Window *window){
 SDL_FillRect(window->surface,NULL,SDL_MapRGB(window->surface->format,255,255,255));
}
