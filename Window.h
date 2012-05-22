#ifndef _WINDOW
#define _WINDOW
struct WINDOW {
SDL_Surface *surface;
int width;
int height;
};
typedef struct WINDOW Window;

Window *createWindow(int ,int ,const char *);
void destroyWindow(Window *);
void flipWindow(Window *);
void refreshWindow(Window *);
#endif
