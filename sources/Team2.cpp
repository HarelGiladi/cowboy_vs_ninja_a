#include "Team2.hpp"
#include "Character.hpp"
#include <vector>

Team2::Team2(const Team2 &other) :Team(other), chief(other.chief){}

Team2::Team2(Character *chief) : Team(chief),chief(chief){team.push_back(chief);}

Team2::Team2(Team2 &&other)noexcept:Team(other) {team = other.team;chief = other.chief;}


Team2 &Team2::operator=(const Team2 &other) {
  team = other.team;
  chief = other.chief;
  return *this;
}

Team2 &Team2::operator=( Team2 &&other) noexcept{
  team = other.team;
  chief = other.chief;
  return *this;
}

Team2::~Team2() {}

int Team2::stillAlive() { return 0; }

void Team2::attack(Team *other) {}
void Team2::print() {}
void Team2::add(Character *teamate) {
  if (team.size() == 10){return;}
  team.push_back(teamate);
}
