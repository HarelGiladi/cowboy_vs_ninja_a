#ifndef TEAM
#define TEAM

#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>

namespace ariel {};

class Team {
  vector<Character *> team;
  Character *chief;

        public:
        Team(const Team& other);
        Team(Character *chief);
        Team(Team&& other)noexcept;
       
        ~Team();
       
        int stillAlive();

        void add(Character *other);
        void attack(Team *other);
        void print();
       
        };

#endif