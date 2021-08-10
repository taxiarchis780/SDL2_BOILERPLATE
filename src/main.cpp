#include <GameClass.h>
#define TITLE "Project"

int main(int argc, char* argv[])
{

    GameClass* Game = new GameClass();

    Game->init(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);

    while(Game->running())
    {
        Game->HandleEvents();
        Game->update();
        Game->render();
    }

    Game->clean();

    return 0;
}