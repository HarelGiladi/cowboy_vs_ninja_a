#ifndef CHARA
#define CHARA

#include <string>
#include "Point.hpp"

using namespace std;

class Character {
  Point location;
  string name;
  int life;

  public:
    Character(string name,  const Point &location, int life);
    Point getLocation();
    bool isAlive();
    double distance(const Character &other);
    int getLife();
    void hit(int number);
    string getName();
    string print();
  };


#endif