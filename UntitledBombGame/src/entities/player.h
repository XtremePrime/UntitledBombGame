#include <SFML/Graphics.hpp>
#include "entity.h"

class Player : public Entity{
private:
	sf::Sprite _player;
	int _lives;
	bool _is_sprinting;
protected:
public:
	void init();
	void update(sf::Time deltaTime);
	void handle_events(sf::Event event);
	void draw(sf::RenderWindow* window);
	
	bool check_collision();
	void move(sf::Time deltaTime);

	int get_lives();
	void set_lives(int new_lives);
};