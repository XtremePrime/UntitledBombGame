#include <SFML/Graphics.hpp>

class Entity{
private:
protected:
	sf::Texture texture;
	float x, y;
	bool is_flipped=false;
public:
	virtual void init() = 0;
	virtual void update(sf::Time deltaTime) = 0;
	virtual void handle_events(sf::Event event) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;

	virtual bool check_collision() = 0;
	virtual void move(sf::Time deltaTime) = 0;
	float get_x(); 
	float get_y();
	void set_x(float new_x);
	void set_y(float new_y);
	
};