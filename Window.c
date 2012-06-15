#include <stdlib.h>
#include "SDL.h"
#include <assert.h>
#include "Window.h"

struct WINDOW *createWindow(int width,int height,const char *title){
 struct WINDOW *ret;
 ret= malloc(sizeof(struct WINDOW));
 ret->width =width;
 ret->height=height;
 ret->surface=SDL_SetVideoMode(ret->width,ret->height,16,SDL_HWSURFACE);
 SDL_WM_SetCaption(title,NULL);
 refreshWindow(ret);
 return ret;
}
void destroyWindow(struct WINDOW *window) {
 SDL_FreeSurface(window->surface);
 window->surface=NULL;
 free(window);
}
void flipWindow(struct WINDOW *window){
 SDL_Flip(window->surface);
}
void refreshWindow(struct WINDOW *window){
 SDL_FillRect(window->surface,NULL,SDL_MapRGB(window->surface->format,255,255,255));
}
