#include "game.h"
#include "save_data.h"

namespace is
{
    Game::Game()
    {
        loadData(); //loads the game data

        sm.initialize();
    }
    
    void Game::update()
    {
        sm.update();
    }
}