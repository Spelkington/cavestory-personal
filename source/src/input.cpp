#include "input.h"
#include "stdio.h"

/**
 * Input Class
 * 
 * Monitors the keyboard state.
 */

/**
 * Called a the start of each new frame, and clears instantaneous states such as pressed/released keys
 */
void Input::beginNewFrame() {

    this->_pressedKeys.clear();
    this->_releasedKeys.clear();

}

void Input::keyDownEvent(const SDL_Event& event) {

    printf(event.key.keysym.scancode + " was pressed");

    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys   [event.key.keysym.scancode] = true;

}

void Input::keyUpEvent(const SDL_Event& event) {

    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys   [event.key.keysym.scancode] = false;

}

bool Input::wasKeyPressed(SDL_Scancode key) {

    return this->_pressedKeys[key];

}


bool Input::wasKeyHeld(SDL_Scancode key) {

    return this->_heldKeys[key];

}

bool Input::wasKeyReleased(SDL_Scancode key) {

    return this->_releasedKeys[key];

}