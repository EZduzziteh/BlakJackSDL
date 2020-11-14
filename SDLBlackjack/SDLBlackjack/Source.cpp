#include <iostream>
#include <SDL.h>

#include <iostream>			/* for cout, cerr */
#include <cstdlib>			/* for atexit() */

#include "Definitions.h"

using namespace std;

int main(int argv, char** argc)  
{
	/** Declare needed Variables */
	SDL_Window		*window;		// What window to draw to
	SDL_Renderer	*renderer;		// Where the image will be drawn to
	SDL_Texture		*texture;			// References background image that will be used
	SDL_Rect		src, dest;		// Describe source and destination regions of Image
	SDL_Texture* texture2;
	SDL_Rect src2, dest2;
	/** Initialize SDL for the Project */
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) 
	{
		/** Display error message */
		cerr << "\nUnable to initialize SDL: " << SDL_GetError() << endl;

		/** End main() */
		return 1; 
	}
	atexit(SDL_Quit);

	/** Create Window for Project */
	window = SDL_CreateWindow("Pong Superstars", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (!window)
	{   
		/** Display error message */
		cerr << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		
		/** End main() */
		return 1; 
	}

	/** Create Renderer to draw on */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{   
		/** Display error message */
		cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		
		/** End main() */
		return 1;
	}

	/** Load Images */
	texture = IMG_LoadTexture(renderer, "Images/Pong_MainMenu.bmp");
	if (!texture)
	{   
		/** Display error message */
		cerr << "IMG_LoadTexture Error: " << IMG_GetError() << endl;
		
		/** End main() */
		return 1;
	}
	texture2 = IMG_LoadTexture(renderer, "Images/Pong_MenuOp1.bmp");
	if (!texture2)
	{
		/** Display error message */
		cerr << "IMG_LoadTexture Error: " << IMG_GetError() << endl;

		/** End main() */
		return 1;
	}
	
	/** Construct SDL_Rects used to draw Image */

	/** Where to get Image from */
	src.x = 0;
	src.y = 0;
	src.h = 480;
	src.w = 640;

	src2.x = 0;
	src2.y = 0;
	src2.h = 50;
	src2.w = 387;

	/** Where to draw Image to */
	dest.x = 0;
	dest.y = 0;
	dest.h = 480;
	dest.w = 640;


	dest2.x = 125;
	dest2.y = 155;
	dest2.h = 50;
	dest2.w = 387;

	/** Clear Screen to prepare for drawing */
	SDL_RenderClear(renderer);

	/** Drawing textures to Screen */
	
	SDL_RenderCopy(renderer, texture, &src, &dest);
	SDL_RenderCopy(renderer, texture2, &src2, &dest2);
	//SDL_RenderCopy(ren, tex, &src, NULL);

	/** Update Screen */
	SDL_RenderPresent(renderer);
	
	/** Pause for 2 seconds */
	SDL_Delay(2000);
	
	/** Clean up Project before closing */
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}