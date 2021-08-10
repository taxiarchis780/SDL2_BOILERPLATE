#include <GameClass.h>
#include <ConsoleMgr.h>





bool GameClass::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    if(!SDL_Init(SDL_INIT_EVERYTHING))
    {
        
        ConsoleMgr::SetColor(ConsoleMgr::ColorGreen);
        std::cout << "SDL(OK): Succesful Initialization" << std::endl;
        ConsoleMgr::ResetColor();

        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        

        if(m_pWindow != 0)
        {
            ConsoleMgr::SetColor(ConsoleMgr::ColorGreen);
            std::cout << "SDL(OK): Succesful Window Initialization" << std::endl;
            ConsoleMgr::ResetColor(); 

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer)
            {
                ConsoleMgr::SetColor(ConsoleMgr::ColorGreen);
                std::cout << "SDL(OK): Succesful Renderer Initialization" << std::endl;
                ConsoleMgr::ResetColor(); 
                SDL_SetRenderDrawColor(m_pRenderer, 8, 20, 30, 255);
            }
            else
            {
                ConsoleMgr::SetColor(ConsoleMgr::ColorRed);
                std::cout << "SDL(FATAL): Renderer Initialization Failed" << std::endl;
                ConsoleMgr::ResetColor();
                return false;
            }
        }
        else
        {
            ConsoleMgr::SetColor(ConsoleMgr::ColorRed);
            std::cout << "SDL(FATAL): Window Initialization Failed" << std::endl;
            ConsoleMgr::ResetColor();
            return false;
        }

    }
    else
    {
        ConsoleMgr::SetColor(ConsoleMgr::ColorRed);
        std::cout << "SDL(FATAL): SDL Failed To Initialize" << std::endl;
        ConsoleMgr::ResetColor();
        return false;
    }

    ConsoleMgr::SetColor(ConsoleMgr::ColorGreen);
    std::cout << "SDL(OK): Succesfully Initialized" << std::endl;
    ConsoleMgr::ResetColor(); 

    m_bRunning = true;

    return true;

}

void GameClass::render()
{
    SDL_RenderClear(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

void GameClass::clean()
{
    ConsoleMgr::SetColor(ConsoleMgr::ColorGreen);
    std::cout << "SDL(OK): Cleaning" << std::endl;
    ConsoleMgr::ResetColor();

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void GameClass::HandleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
            break;
            default:
            break;
        }

    }
}