#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "states/introstate.h"

int main()
{
    Game game;
    game.init();

    game.change_state(IntroState::instance());

    sf::Clock clock;

    // Game loop
    while(game.is_running()){
        sf::Time deltaTime = clock.restart();

        game.handle_events();
        game.update(deltaTime);
        game.draw();
    }
    game.cleanup();

    return 0;
}
