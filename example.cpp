#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <unistd.h>
#include <SDL2/SDL.h>
bool init();

int main() {
	// initialized the SDL for everything
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error\n");
		return -1;
	}

	SDL_Window *win = NULL;
	win = SDL_CreateWindow("Tic Tac Toe", 100, 100, 1080, 720, SDL_WINDOW_SHOWN );
	if (win == NULL)
	{
		printf("Error\n");
		return -1;
	}

	SDL_Surface* winSurface = NULL; 
	winSurface = SDL_GetWindowSurface(win);
	SDL_Rect rects[4];
	rects[0].x = 100;
	rects[0].y = 100;
	rects[0].w = 100;
	rects[0].h = 100;
	
	rects[1].x = 250;
	rects[1].y = 100;
	rects[1].w = 100;
	rects[1].h = 100;

	rects[2].x = 400;
	rects[2].y = 250;
	rects[2].w = 100;
	rects[2].h = 100;

	rects[3].x = 550;
	rects[3].y = 100;
	rects[3].w = 100;
	rects[3].h = 100;

	for(int i = 0 ;i<255; i++)
	{
		rects[2].y += 110;
		SDL_FillRect(winSurface, &rects[0], SDL_MapRGB( winSurface->format, i, 90, 255 ));
		SDL_FillRect(winSurface, &rects[1], SDL_MapRGB( winSurface->format, 90, i, 255-i ));
		SDL_FillRect(winSurface, &rects[2], SDL_MapRGB( winSurface->format, 90, 90, i ));
		SDL_FillRect(winSurface, &rects[3], SDL_MapRGB( winSurface->format, i, i, 0 ));
		SDL_UpdateWindowSurface(win);
		usleep(16666);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
