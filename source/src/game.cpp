#include <SDL2/SDL.h>
#include <algorithm>
#include "game.h"
#include "graphics.h"
#include "input.h"

/**
 * Game Class
 * 
 * Handles high-level game logic, such as the game loop and
 * updating the window.
 * 
 */

namespace {

    const int FPS = 50;
    const int FRAME_PERIOD = 1000 / FPS;
    const int MAX_FRAME_TIME = 5 * FRAME_PERIOD;

}

Game::Game() {

    SDL_Init(SDL_INIT_EVERYTHING);

    this->gameLoop();

    return;

}

Game::~Game() {

    return;

}

void Game::gameLoop() {

    Graphics graphics;
    Input input;

    // Holds everything that happens between frames (e.g. inputs)
    SDL_Event event;
    _player = Sprite(graphics, "sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

    // Start monitoring time
    int LAST_UPDATE_TIME = SDL_GetTicks();

    // Start game loop
    while(true) {

        // If there were any events that occurred since the last frame,
        if (SDL_PollEvent(&event)) {

            switch (event.type){

                case SDL_QUIT:
                    return;

                case SDL_KEYDOWN:
                    if (event.key.repeat == 0) {

                        input.keyDownEvent(event);

                    }

                    // Exit on escape
                    if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
                        return;
                    }

            }

            // Halt until the proper frame length is reached.
            const int CURRENT_TIME_MS = SDL_GetTicks();
            int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

            this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

            LAST_UPDATE_TIME = CURRENT_TIME_MS;

            this->draw(graphics);

        }

    }

    return;

}

void Game::draw(Graphics &graphics) {

    graphics.clear();

    _player.draw(graphics, 100, 100);

    graphics.flip();

    return;

}

void Game::update(float elapsedTime) {

    return;
    
}