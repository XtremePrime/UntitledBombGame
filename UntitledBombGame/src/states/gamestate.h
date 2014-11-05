#include <SFML/Graphics.hpp>
#include "state.h"
#include "../entities/player.h"

class GameState : public State{
private:
	Player player;
	sf::Texture _texture;
	sf::Sprite _tiles[15][15];
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