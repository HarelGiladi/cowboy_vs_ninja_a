#include "Character.hpp"

Character::Character(string name, const Point &location, int life)
    : name(name), location(location), life(life) {}

int Character::getLife() {return life;}
double Character::distance(const Character &other) {return 0.0; }
bool Character::isAlive() { return true;}
void Character::hit(int damage) {}
Point Character::getLocation() {return location; }
string Character::getName() {return "HAREL"; }
string Character::print() {return name; }