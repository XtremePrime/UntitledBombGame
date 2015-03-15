#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity{
private:
protected:
	sf::Texture texture;
	sf::Vector2f coord;
	// float x, y;
	bool is_flipped=false;

	int _hp, _dmg, _max_hp;
public:
	virtual void init() = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void handle_events(sf::Event event) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	virtual bool check_wall_collision() = 0;
	virtual void move(sf::Time deltaTime) = 0;
	
	float get_x(); 
	float get_y();
	int get_hp();
	int get_dmg();
	int get_max_hp();
	void set_x(float);
	void set_y(float);
	void set_hp(int);
	void set_dmg(int);
	void set_max_hp(int);
	
};

#endif // ENTITY_H