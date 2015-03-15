#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "state.h"
#include "../entities/player.h"

class GameState : public State{
private:
	Player player;
	sf::Texture _texture;
	sf::Sprite _tiles[20][20];

	//- UI text
	sf::Font _font;
	sf::Text _ui_lives;
	sf::Text _ui_level;
	sf::Text _ui_xp;
protected:
	static GameState* _instance;
	GameState(){}
public:
	static GameState* instance();
    ~GameState(){}

	virtual void init();
	virtual void cleanup();

	virtual void handle_events(Game* game, sf::Event event);
	virtual void update(Game* game, sf::Time deltaTime);
	virtual void draw(Game* game);

 	virtual void pause();
 	virtual void resume();
};

#endif // GAMESTATE_H