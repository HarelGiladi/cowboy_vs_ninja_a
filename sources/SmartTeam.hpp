#ifndef SMART
#define SMART

#include "Team.hpp"
#include "Character.hpp"
#include <vector>

namespace ariel {};

class SmartTeam : public Team {
  
  vector<Character *> team;
  Character *chief;

        public:
        SmartTeam(const SmartTeam &other);
        SmartTeam(Character *chief);
        SmartTeam(SmartTeam &&other) noexcept;
        SmartTeam &operator=(const SmartTeam &other);
        SmartTeam &operator=(SmartTeam &&other) noexcept;
        ~SmartTeam();

        int stillAlive();
        
        void add(Character *other);
        void attack(Team *other);
        void print();
        };


#endif