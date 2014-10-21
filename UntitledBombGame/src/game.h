#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class State;
class Game{
private:
	sf::RenderWindow _window;
	bool _running;
	std::vector<State*> _state_stack;
	sf::Event _event;
public:
	static const int GAME_WIDTH = 640, GAME_HEIGHT = 480;
	sf::RenderWindow* get_window(){ return &_window; }
	void init();
	void cleanup();

	void handle_events();
	void update(sf::Time deltaTime);
	void draw();

	void change_state(State* state);
	void push_state(State* state);
	void pop_state();

	bool is_running(){ return _running; }
	void quit() {
		_running = false;
		_window.close();
	}
};

#endif // GAME_H