#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "state.h"
#include "introstate.h"

IntroState* IntroState::_instance;

IntroState* IntroState::instance(){
	if(_instance == NULL) _instance = new IntroState();
	return _instance;
}

void IntroState::init(){
	if(!_font.loadFromFile("res/font/PressStart2P.ttf"))
		std::cout << "res/font/PressStart2P.ttf not loaded.\n";

	_title.setFont(_font);
	_title.setString("Untitled Bomb Game");
	_title.setColor(sf::Color(255,255,255));
	_title.setCharacterSize(30);
	_title.setPosition(20, 20);
}

void IntroState::cleanup(){

}

void IntroState::handle_events(Game* game, sf::Event event){

}

void IntroState::update(Game* game, sf::Time deltaTime){

}

void IntroState::draw(Game* game){
	game->get_window()->draw(_title);
}

void IntroState::pause(){

}

void IntroState::resume(){

}