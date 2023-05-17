#include "Ninja.hpp"
#include "Character.hpp"


Ninja::Ninja(string name, const Point &location, int life, int speed)
    : Character(name, location, life), speed(speed) {}

void Ninja::move(const Character *other) {}
void Ninja::slash(Character *other) {}