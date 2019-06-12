#ifndef GAME_H
#define GAME_H

#include "animated_sprite.h"

class Graphics;

class Game {

    public:
        Game();
        ~Game();
    
    private:
        void gameLoop();
        void draw(Graphics &graphics);
        void update(float timeElapsed);

        AnimatedSprite _player;
};

#endif