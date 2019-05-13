#include "graphics.h"
#include "globals.h"

extern "C"{
    #include "SDL2/SDL.h"
    #include "SDL2/SDL_image.h"
}

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

    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH,
                                globals::SCREEN_HEIGHT,
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

SDL_Surface* Graphics::loadImage(const std::string &filePath) {

    if (this->_spriteSheets.count(filePath) == 0) {

        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());

    }

    return _spriteSheets[filePath];

}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {

    SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);

}

void Graphics::flip() {

    SDL_RenderPresent(_renderer);

}

void Graphics::clear() {
    SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {

    return _renderer;

}