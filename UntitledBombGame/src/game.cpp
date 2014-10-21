#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.h"
#include "states/state.h"

using namespace std;

void Game::init(){
    // Initializing the game
    _window.create(sf::VideoMode(GAME_WIDTH,GAME_HEIGHT), "Untitled Bomb Game", sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(60);

    _running = true;

    _window.setKeyRepeatEnabled(false);
}
void Game::cleanup(){
    _window.close();
}

void Game::handle_events(){
    // Handling the main window events first
    while(_window.pollEvent(_event))
    {
        _state_stack.back()->handle_events(this, _event);

        switch(_event.type)
        {
            case sf::Event::KeyPressed:
            if(event.key.code == sf::Keyboard::Escape)
                    quit();
                break;
            case sf::Event::Closed:
                quit();
                break;
            default:
                break;
        }
    }
}
void Game::update(sf::Time deltaTime){
    _state_stack.back()->update(this, deltaTime);
}
void Game::draw(){
    _state_stack.back()->draw(this);

    _window.display();
    _window.clear();
}

void Game::change_state(State* state){
    // Cleanup the current state
    if (!_state_stack.empty()){
        _state_stack.back()->cleanup();
        _state_stack.pop_back();
    }

    // Store and init the new state
    _state_stack.push_back(state);
    _state_stack.back()->init();
}
void Game::push_state(State* state){
    // Pause current state
    if (!_state_stack.empty())
        _state_stack.back()->pause();

    // Store and init the new state
    _state_stack.push_back(state);
    _state_stack.back()->init();
}
void Game::pop_state(){
    // Cleanup the current state
    if (!_state_stack.empty()){
        _state_stack.back()->cleanup();
        _state_stack.pop_back();
    }

    // Resume previous state
    if (!_state_stack.empty())
        _state_stack.back()->resume();
}
