#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>

SmartTeam::SmartTeam(const SmartTeam &other): Team(other), chief(other.chief){}

SmartTeam::SmartTeam(Character *chief) : Team(chief), chief(chief) {team.push_back(chief);}

SmartTeam::SmartTeam(SmartTeam &&other) noexcept : Team(other){team = other.team;chief = other.chief;}

SmartTeam &SmartTeam::operator=(const SmartTeam &other) {
  team = other.team;
  chief = other.chief;
  return *this;
}

SmartTeam &SmartTeam::operator=(SmartTeam &&other) noexcept {
  team = other.team;
  chief = other.chief;
  return *this;
}

SmartTeam::~SmartTeam() {}


int SmartTeam::stillAlive() { return 0; }


void SmartTeam::print() {}
void SmartTeam::attack(Team *other) {}
void SmartTeam::add(Character *member) {
  if (team.size() == 10){return;}
  team.push_back(member);
}
