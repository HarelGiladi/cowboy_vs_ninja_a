#ifndef TEAM2
#define TEAM2

#include "Team.hpp"
#include <vector>

namespace ariel {};

class Team2:public Team{
  vector<Character *> team;
  Character *chief;

        public:
        Team2(const Team2& other);
        Team2(Character *chief);
        Team2(Team2&& other)noexcept;
        
        ~Team2();
        
        int stillAlive();
        
        void add(Character *other);
        void attack(Team *other);
        void print();
        };

#endif