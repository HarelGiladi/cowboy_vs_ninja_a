#include "Cowboy.hpp"
#include "Character.hpp"

Cowboy::Cowboy(string name, const Point &location)
    : Character(name, location, 576), bullets_num(22) {}

bool Cowboy::hasBullets() { return true;}

void Cowboy::shoot(Character *other) {}
void Cowboy::reload() {}