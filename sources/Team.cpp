#include "Team.hpp"
#include "Character.hpp"
#include <vector>

Team::Team(const Team &other) : chief(other.chief){}

Team::Team(Character *chief) : chief(chief){team.push_back(chief); }

Team::Team(Team &&other)noexcept{chief = other.chief;team = other.team;}

Team &Team::operator=(const Team &other){
  team = other.team;
  chief = other.chief;
  return *this;
}

Team &Team::operator=( Team &&other) noexcept{
  team = other.team;
  chief = other.chief;
  return *this;
}
Team::~Team(){}

int Team::stillAlive(){return 0;}

void Team::attack(Team *other){}
void Team::print(){}
void Team::add(Character *teamate){
  if (team.size() == 10){return;}
  team.push_back(teamate);
}

