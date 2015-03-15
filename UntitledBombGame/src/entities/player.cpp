#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

#include "player.h"

void Player::init()
{
	texture.loadFromFile("res/sprite/player/moonwalk_0.png");
	_player.setTexture(texture);
	_player.setScale(2, 2);
	coord.x = 200; coord.y = 200;

	_lives=3;
	_is_sprinting=false;
}
void Player::update(sf::Time deltaTime)
{
	//if(check_wall_collision())
	move(deltaTime);

	_player.setPosition(coord.x, coord.y);


	if(_xp == (_level*_level*_level)/2)
		_level++;
}
void Player::handle_events(sf::Event event)
{
	if(event.key.shift)
		_is_sprinting=true;
	else
		_is_sprinting=false;

	if(event.type == sf::Event::KeyReleased)
	{
		if(event.key.code == sf::Keyboard::C)
			_xp++;
	}
	
}
bool Player::check_wall_collision()
{
	if(coord.x-1.f <= 0 || coord.x+1.f >= 480)
		return true;
	if(coord.y-1.f <= 0 || coord.y+1.f >= 480)
		return true;

	return false;
}
void Player::move(sf::Time deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		// if(check_wall_collision())
		// {
			if(!_is_sprinting)	coord.x -= 1;
			else				coord.x -= 2.5;
		// }
		_player.setTextureRect(sf::IntRect(32, 0, -32, 32));
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if(!_is_sprinting)
			coord.x += 1;
		else
			coord.x+=2.5f;
		_player.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(!_is_sprinting)
			coord.y--;
		else
			coord.y-=2.5f;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if(!_is_sprinting)
			coord.y++;
		else
			coord.y+=2.5f;
	}
}
void Player::draw(sf::RenderWindow* window)
{
	window->draw(_player);
}

int Player::get_lives(){return _lives;}
void Player::set_lives(int lives){_lives = lives;}
int Player::get_level(){return _level;}
void Player::set_level(int level){_level = level;}
int Player::get_xp(){return _xp;}
void Player::set_xp(int xp){_xp = xp;}