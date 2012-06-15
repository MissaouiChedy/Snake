#ifndef _WINDOW
#define _WINDOW
struct WINDOW {
SDL_Surface *surface;
int width;
int height;
};
struct WINDOW *createWindow(int ,int ,const char *);
void destroyWindow(struct WINDOW *);
void flipWindow(struct WINDOW *);
void refreshWindow(struct WINDOW *);
#endif
