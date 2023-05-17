#ifndef NINJA
#define NINJA

#include "Character.hpp"

constexpr int young_life = 100;
constexpr int young_speed = 14;

constexpr int old_life = 150;
constexpr int old_speed = 18;

constexpr int trained_life = 120;
constexpr int trained_speed = 12;

class Ninja : public Character {
  int speed;

        public:
        Ninja(string name, const Point &location, int life, int speed);
        void move(const Character *other);
        void slash(Character *other);
        };



class TrainedNinja : public Ninja {

        public:
        TrainedNinja(string name, const Point &location)
        : Ninja(std::move(name), location, trained_life, trained_speed) {}
        };



class YoungNinja : public Ninja {

        public:
        YoungNinja(string name, const Point &location)
        : Ninja(std::move(name), location, young_life, young_speed) {}
        };




class OldNinja : public Ninja {

        public:
        OldNinja(string name, const Point &location)
        : Ninja(std::move(name), location, old_life, old_speed) {}
        };


#endif