#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"

class Player : public Entity{
private:
	sf::Sprite _player;
	int _lives;
	bool _is_sprinting;
	int _level=1, _xp=0;
protected:
public:
	void init();
	void update(sf::Time deltaTime);
	void handle_events(sf::Event event);
	void draw(sf::RenderWindow* window);
	
	bool check_wall_collision();
	void move(sf::Time deltaTime);

	int get_level();
	int get_lives();
	int get_xp();
	void set_level(int);
	void set_lives(int);
	void set_xp(int);
};

#endif // PLAYER_H