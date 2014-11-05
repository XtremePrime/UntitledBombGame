#include <SFML/Graphics.hpp>
#include "gamestate.h"
#include "state.h"
#include <iostream>

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
	
	_texture.loadFromFile("res/img/grass_no_border.png");
	for(int x = 0; x < TILES_ROW; ++x)
	{
		for(int y = 0; y < TILES_COL; ++y)
		{
			_tiles[x][y].setTexture(_texture);
			_tiles[x][y].setPosition(x*32,y*32);
		}
	}
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
}

void GameState::pause()
{

}

void GameState::resume()
{

}
