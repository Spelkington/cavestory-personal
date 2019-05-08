#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {

    public:
        Graphics();
        ~Graphics();
    
    private:
        SDL_Renderer* _renderer;
        SDL_Window*   _window;

};

#endif