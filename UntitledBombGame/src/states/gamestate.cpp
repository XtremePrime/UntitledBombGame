#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "state.h"
#include <iostream>
#include <sstream>

#define TILES_ROW 15
#define TILES_COL 15

GameState* GameState::_instance;

GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init()
{
	player.init();
	
	_texture.loadFromFile("res/img/rock.png");
	for(int x = 0; x < TILES_ROW; ++x)
	{
		for(int y = 0; y < TILES_COL; ++y)
		{
			_tiles[x][y].setTexture(_texture);
			_tiles[x][y].setPosition(x*32,y*32);
		}
	}

	if(!_font.loadFromFile("res/font/PressStart2P.ttf"))
		std::cout << "res/font/PressStart2P.ttf not loaded.\n";

	
	_ui_level.setFont(_font);
	_ui_level.setString("Level: 0");
	_ui_level.setColor(sf::Color(255,255,255));
	_ui_level.setCharacterSize(25);
	_ui_level.setPosition(0, 0);

	_ui_xp.setFont(_font);
	_ui_xp.setString("XP: 0");
	_ui_xp.setColor(sf::Color(255,255,255));
	_ui_xp.setCharacterSize(25);
	_ui_xp.setPosition(0, 32);

	_ui_lives.setFont(_font);
	_ui_lives.setString("");
}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{
	player.handle_events(event);
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	player.update(deltaTime);

	std::stringstream ss;
	ss << "Level: " << player.get_level();
	_ui_level.setString(ss.str());
	ss.str(std::string());
	ss.clear();
	ss << "XP: " << player.get_xp();
	_ui_xp.setString(ss.str());
	ss.str(std::string());
	ss.clear();
}

void GameState::draw(Game* game)
{
	for(int x = 0; x < TILES_ROW; ++x)
	{
		for(int y = 0; y < TILES_COL; ++y)
		{
			game->get_window()->draw(_tiles[x][y]);
		}
	}

	player.draw(game->get_window());

	game->get_window()->draw(_ui_level);
	game->get_window()->draw(_ui_xp);
	// game->get_window()->draw(_ui_lives);
}

void GameState::pause()
{

}

void GameState::resume()
{

}
