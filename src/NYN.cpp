// NYN.cpp : Defines the entry point for the application.
//

#include "NYN.h"

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* gHelloWorld;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		success = false;
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	} else {
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			success = false;
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;

	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL) {
		success = false;
		std::cout << "Error loading image. SDL Error: " << SDL_GetError() << std::endl;
	}
	return success;
}

void blit() {
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
}

void close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event e;

	if (!init()) {
		std::cout << "Failed to initalize!" << std::endl;
		quit = true;
	} else {
		if (!loadMedia()) {
			std::cout << "Failed to load media!" << std::endl;
			quit = true;
		}
	}
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
	}
	return 0;
}
