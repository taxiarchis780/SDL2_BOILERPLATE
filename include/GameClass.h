#ifndef __GameClass__
#define __GameClass__

#include <SDL2/SDL.h>
#include <iostream>

class GameClass
{

public:
    GameClass() {};
    ~GameClass() {};

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update() {};
    void HandleEvents();
    void clean();

    bool running() {return m_bRunning;}

private:
    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
};


#endif