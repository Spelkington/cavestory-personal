#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Rect;
struct SDL_Texture;

#include <map>
#include <string>

class Graphics {

    public:
        /**
         * Creates a new Graphics class, instantiating a new drawable window.
         */
        Graphics();
        
        ~Graphics();

        /**
         * Loads an image into _spriteSheets if it does not already exist. 
         * Each image loaded through loadImage will only ever be loaded once.
         * 
         * Always returns the image from _spriateSheets.
         */
        SDL_Surface* loadImage(const std::string &filePath);

        /**
         * Draws a texture to the screen at the destination rectangle.
         */
        void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

        /**
         * Renders everything to the screen
         */
        void flip();

        /**
         * Clears everything from the screen.
         */
        void clear();

        /**
         * Returns the renderer used in this Graphics object.
         */
        SDL_Renderer* getRenderer() const;

    private:
        /**
         * The SDL Renderer determining how the game will be drawn.
         */
        SDL_Renderer* _renderer;
        SDL_Window*   _window;

        std::map<std::string, SDL_Surface*> _spriteSheets;

};

#endif