#include "graphics.h"

#include <SDL2/SDL.h>

/**
 * Graphics Class
 * 
 * This class will deal with all necessary graphical outputs for the
 * game.
 */

/**
 * Default Graphics constructor.
 */
Graphics::Graphics() {

    SDL_CreateWindowAndRenderer(640,
                                480,
                                0,
                                &_window,
                                &_renderer);

    SDL_SetWindowTitle(_window, "Cave Story");

}

/**
 * Graphics Object destructor. Removes the window and all necessary rendering elements.
 */
Graphics::~Graphics() {

    SDL_DestroyWindow(_window);

}