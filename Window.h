#ifndef _WINDOW
#define _WINDOW
#include <stdlib.h>
#include "SDL.h"
#include <assert.h>
struct WINDOW {
SDL_Surface *surface;
int width;
int height;
};
typedef struct WINDOW Window;

void refreshWindow(Window *window){

 SDL_FillRect(window->surface,NULL,SDL_MapRGB(window->surface->format,255,255,255));

}

Window createWindow(int width,int height,const char *title){
 Window ret;
 ret.width =width;
 ret.height=height;
 ret.surface=SDL_SetVideoMode(ret.width,ret.height,16,SDL_HWSURFACE);
 SDL_WM_SetCaption(title,NULL);
 refreshWindow(&ret);
 return ret;
}
void destroyWindow(Window window) {
 SDL_FreeSurface(window.surface);
 window.surface=NULL;
}
void flipWindow(Window *window){
 SDL_Flip(window->surface);
}
#endif
