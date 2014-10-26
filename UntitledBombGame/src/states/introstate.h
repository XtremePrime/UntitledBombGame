#ifndef INTROSTATE_H
#define INTROSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "state.h"

class IntroState : public State{
private:
	sf::Font _font;
	sf::Text _title;
protected:
	static IntroState* _instance;
	IntroState(){}
public:
	static IntroState* instance();
    ~IntroState(){

    }

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(Game* game, sf::Event event);
	virtual void update(Game* game, sf::Time deltaTime);
	virtual void draw(Game* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // INTROSTATE_H