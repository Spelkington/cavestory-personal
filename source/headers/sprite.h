#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <graphics.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {

    public:
        Sprite();
        Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
        virtual ~Sprite(); // Virtual because this will likely be overwritten for animated sprites.
        
        virtual void update(); // See destructor for virtual explanation.

        /**
         * Draw sprite at location.
         */
        void draw(Graphics &graphics, int x, int y);

    private:
        SDL_Rect _sourceRect;
        SDL_Texture* _spriteSheet;

        float _x, _y;

};

#endif