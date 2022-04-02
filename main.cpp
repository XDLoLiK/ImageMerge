/**
 * @defgroup   MAIN main
 *
 * @brief      This file implements main.
 *
 * @author     Stanislav
 * @date       2022
 */

#include "imageMerge.h"

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window  *mainWindow = SDL_CreateWindow("Image Merge",SDL_WINDOWPOS_CENTERED, 
                                               SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    assert(mainWindow != nullptr);
    SDL_SetWindowBordered(mainWindow, SDL_FALSE);

	int retValue = 0;

	if (argc < 3) {
		retValue = 1;
	} else {
		retValue = MergeImages(mainWindow, argv[1], argv[2]);
	}

    SDL_Quit();
	return retValue;
}
