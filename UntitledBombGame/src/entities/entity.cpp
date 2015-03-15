#include <SFML/Graphics.hpp>

#include "entity.h"

//- Accessors
float Entity::get_x(){return coord.x;}
float Entity::get_y(){return coord.y;}
int Entity::get_hp(){return _hp;}
int Entity::get_dmg(){return _dmg;}
int Entity::get_max_hp(){return _max_hp;}

void Entity::set_x(float new_x){coord.x = new_x;}
void Entity::set_y(float new_y){coord.y = new_y;}
void Entity::set_hp(int hp){_hp=hp;}
void Entity::set_dmg(int dmg){_dmg=dmg;}
void Entity::set_max_hp(int max_hp){_max_hp=max_hp;}
