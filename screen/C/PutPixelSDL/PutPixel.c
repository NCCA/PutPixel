#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>

//-----------------------------------------------------------------------------
/// @brief simple SDL clear screen function
/// @param [in] _screen a pointer to the SDL screen structure
/// @param [in] _r the red component for the clear colour 0-255
/// @param [in] _g the green component for the clear colour 0-255
/// @param [in] _b the blue component for the clear colour 0-255
//-----------------------------------------------------------------------------
void clearScreen(SDL_Renderer *_ren,char _r,char _g,char _b);

//-----------------------------------------------------------------------------
/// @brief function to quit SDL with error message
/// @param[in] _msg the error message to send
//-----------------------------------------------------------------------------
void SDLErrorExit(const char *_msg);


int main()
{
	//-----------------------------------------------------------------------------
	// First thing we need to do is initialise SDL in this case we are
	// setting up just the video subsystem if we need audio or timer etc
	// we would | (or) the flags together see http://www.libsdl.org/intro.en/usinginit.html
	// we check the return value and if not 0 it is an error
	//-----------------------------------------------------------------------------
	if (SDL_Init( SDL_INIT_VIDEO ) !=0)
	{
		SDLErrorExit("error initialising SDL");
	}
	//-----------------------------------------------------------------------------
	// next we create a window and make sure it works
	//-----------------------------------------------------------------------------
	SDL_Window *win = 0;
	win = SDL_CreateWindow("PutPixel", 0, 0, 100, 100, SDL_WINDOW_SHOWN);
	if (win == 0)
	{
			SDLErrorExit("Error creating Window");
	}
	//-----------------------------------------------------------------------------
	// now we associate a renderer with the window
	//-----------------------------------------------------------------------------
	SDL_Renderer *renderer = 0;
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == 0)
	{
		SDLErrorExit("error creating renderer");
	}

	clearScreen(renderer,255,255,255);
	SDL_RenderPresent(renderer);

	SDL_Event event;
	bool quit=false;
	// now we loop until the quit flag is set to true
	while(!quit)
	{
			SDL_SetRenderDrawColor(renderer, 255,0,0,255);
			SDL_RenderDrawPoint(renderer,0,0);
			SDL_SetRenderDrawColor(renderer, 0,255,0,255);
			SDL_RenderDrawPoint(renderer,1,0);
			SDL_SetRenderDrawColor(renderer, 0,0,255,255);
			SDL_RenderDrawPoint(renderer,2,0);

		// finally we need to tell SDL to update the screen
		SDL_RenderPresent(renderer);

		// process SDL events, in this case we are looking for keys
		while ( SDL_PollEvent(&event) )
		{
			switch (event.type)
			{
				// this is the window x being clicked.
				case SDL_QUIT : quit = true; break;

				// now we look for a keydown event
				case SDL_KEYDOWN:
				{
					switch( event.key.keysym.sym )
					{
						// if it's the escape key quit
						case SDLK_ESCAPE :  quit = true; break;
						default : break;
					}
				}

				default : break;
			}
		}

		SDL_Delay(1);
	} // end processing loop

	// finally when we are done we need to tidy up SDL by calling SDL_Quit
	// sometime this is added as the atexit function to make it happen
	// automatically
	SDL_Quit();

	return EXIT_SUCCESS;
}



//-----------------------------------------------------------------------------
void clearScreen(SDL_Renderer *_ren,char _r,char _g,char _b	)
{
	SDL_SetRenderDrawColor(_ren, _r,_g,_b,255);
	SDL_RenderClear(_ren);
}




//-----------------------------------------------------------------------------
void SDLErrorExit(const char *_msg)
{
  printf("%s \n",_msg);
  printf("%s\n",SDL_GetError());
  SDL_Quit();
  exit(EXIT_FAILURE);
}
