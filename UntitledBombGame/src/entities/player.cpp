#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Player::init()
{
	texture.loadFromFile("res/img/potato.png");
	_player.setTexture(texture);

	_lives=3;
	_is_sprinting=false;
}
void Player::update(sf::Time deltaTime)
{
	move(deltaTime);
	_player.setPosition(x, y);
	std::cout << "x: " << x << "\ny: " << y << "\n";
}
void Player::handle_events(sf::Event event)
{
	if(event.key.shift)
		_is_sprinting=true;
	else
		_is_sprinting=false;
}
bool Player::check_collision()
{
	return false;
}
void Player::move(sf::Time deltaTime)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(!_is_sprinting)
			x -= 1;
		else
			x-=5;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if(!_is_sprinting)
			x += 1;
		else
			x+=5;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(!_is_sprinting)
			y--;
		else
			y-=5;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(!_is_sprinting)
			y++;
		else
			y+=5;
	}
}
void Player::draw(sf::RenderWindow* window)
{
	window->draw(_player);
}

int Player::get_lives()
{
	return _lives;
}

void Player::set_lives(int new_lives)
{
	_lives = new_lives;
}