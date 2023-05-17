#ifndef COWB
#define COWB

#include "Character.hpp"

class Cowboy : public Character {
  int bullets_num;

public:
  Cowboy(string name,const Point &location);
  void shoot(Character* other);
  bool hasBullets();
  void reload();
};

#endif