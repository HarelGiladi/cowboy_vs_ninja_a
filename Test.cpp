#include "doctest.h"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Point.hpp"
#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"

TEST_CASE("points constructor:)") {
  //cons
  Point p1(0, 10);
  Point p2(20, 0);
  Point *pp = new Point(33,33);

  CHECK(pp != NULL);

  CHECK(p1.distance(Point(0, 0)) == 10);
  CHECK(p2.distance(Point(0, 0)) == 20);

  CHECK_FALSE(p1.distance(Point(0, 0)) == 111);
  CHECK_FALSE(p1.distance(Point(0, 0)) == 222);
}

TEST_CASE("points distance:)") {
  Point p1(0, 10);
  Point p2(20, 0);

//distance
  CHECK(p1.distance(Point(0, 0)) == 10);
  CHECK_FALSE(p1.distance(Point(0, 0)) == 111);

  CHECK(p2.distance(Point(0, 0)) == 20);
  CHECK_FALSE(p1.distance(Point(0, 0)) == 222);
}

TEST_CASE("points move:)") {
  Point p1(0, 10);
  Point p2(20, 0);

  // move
  Point p3 = Point::moveTowards(p1, p2, 1.5);
  CHECK(p1.distance(p3) == 1.5);

  Point p4 = Point::moveTowards(p1, p2, 31);
  CHECK(p1.distance(p4) == p1.distance(p2));
}



TEST_CASE("cowboy  constructors:) ") {
//cons
  Cowboy harel("harel", Point(1, 1));
  Cowboy *giladi2 = new Cowboy("giladi2", Point(2001, 2023));
  OldNinja giladi("giladi", Point(4, 4));

  CHECK(giladi2 != NULL);
  CHECK_THROWS(harel.shoot(&harel));
  harel.shoot(&giladi);
}


TEST_CASE("cowboy  shoots:) ") {
  Cowboy harel("harel", Point(1, 1));
  OldNinja giladi("giladi", Point(4, 4));

//shoot
  CHECK_THROWS(harel.shoot(&harel));
  CHECK_THROWS(harel.shoot(&giladi)) ;
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
}



TEST_CASE("cowboy  getlife:) ") {
  Cowboy harel("harel", Point(1, 1));
  OldNinja giladi("giladi", Point(4, 4));

//life
  int lliiffee = giladi.getLife();
  harel.shoot(&giladi);
  CHECK(lliiffee == giladi.getLife());
}

TEST_CASE("cowboy  reload:) ") {
  Cowboy harel("harel", Point(1, 1));
  OldNinja giladi("giladi", Point(4, 4));

  // reload
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  CHECK(harel.hasBullets()== false);
  harel.reload();
  CHECK(harel.hasBullets());
}

TEST_CASE("cowboy  has bullets:) ") {
  Cowboy harel("harel", Point(1, 1));
  OldNinja giladi("giladi", Point(4, 4));

//bullets
  CHECK(harel.hasBullets());
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  harel.shoot(&giladi);
  CHECK_FALSE(harel.hasBullets());
}



TEST_CASE("ninja constructor and everything:)"){
  TrainedNinja harel("harel",Point(4 , 3 ));
  YoungNinja giladi("giladi",Point(2001, 2023));
  TrainedNinja *trained = new TrainedNinja("trained",Point(21,22));

  CHECK(trained != NULL);

  int lifeee = harel.getLife();
  giladi.slash(&harel);
  CHECK(lifeee==harel.getLife());
}
TEST_CASE("ninja slash:)"){
  TrainedNinja harel("harel",Point(4 , 3 ));
  YoungNinja giladi("giladi",Point(2001, 2023));
  
  giladi.slash(&harel);
}

TEST_CASE("ninja life:)"){
  TrainedNinja harel("harel",Point(4 , 3 ));
  
  int lifeee = harel.getLife();
  CHECK(lifeee==harel.getLife());
}

TEST_CASE("team constructor:)") {
  Cowboy *harel = new Cowboy("harel", Point(26, 5));
  Cowboy *giladi = new Cowboy("giladi", Point(2001, 2023));

  CHECK(harel != NULL);
  CHECK(giladi != NULL);

  Team t1(harel);
}


TEST_CASE("team add:)") {
  Cowboy *harel = new Cowboy("harel", Point(26, 5));
  Cowboy *giladi = new Cowboy("giladi", Point(2001, 2023));

//add
  Team t1(harel);
  CHECK_THROWS(t1.add(harel));
  t1.add(giladi);
  CHECK_THROWS(t1.add(giladi));

  t1.add(new Cowboy("hg", Point(1, 1)));
  t1.add(new Cowboy("hg", Point(2, 2)));
  t1.add(new Cowboy("hg", Point(3, 3)));
  t1.add(new Cowboy("hg", Point(4, 4)));
  t1.add(new Cowboy("hg", Point(5,5)));
  t1.add(new Cowboy("hg", Point(6,6)));
  t1.add(new Cowboy("hg", Point(7, 7)));
  t1.add(new Cowboy("hg", Point(8,8)));
  CHECK_THROWS(t1.add(new Cowboy("hg", Point(1, 1))));
}


TEST_CASE("team attack:)") {
  Cowboy *harel = new Cowboy("harel", Point(26, 5));
  Cowboy *giladi = new Cowboy("giladi", Point(2001, 2023));

//attack 
  Team t1(harel);
  CHECK_THROWS(t1.attack(NULL));
  CHECK_THROWS(t1.attack(&t1));
}



TEST_CASE("SmartTeam constructor:)"){
  Cowboy harel("harel",Point(1,1));
  Cowboy giladi("giladi",Point(2,2));
  Cowboy hg("hg",Point(3,3));

  OldNinja old_harel("old_harel",Point(4,4));
  TrainedNinja trained_harel("trained_harel",Point(5,5));
  YoungNinja young_harel("young_harel",Point(6,6));
  
  SmartTeam smart_team(&harel);
  
  smart_team.add(&giladi);
  smart_team.add(&hg);
  smart_team.add(&old_harel);
  smart_team.add(&trained_harel);
  smart_team.add(&young_harel);
  CHECK(smart_team.stillAlive());
}

TEST_CASE("SmartTeam still alive after attack and adds:)"){
  Cowboy harel("harel",Point(1,1));
  Cowboy giladi("giladi",Point(2,2));
  Cowboy hg("hg",Point(3,3));

  OldNinja old_harel("old_harel",Point(4,4));
  TrainedNinja trained_harel("trained_harel",Point(5,5));
  YoungNinja young_harel("young_harel",Point(6,6));
  
  SmartTeam smart_team(&harel);
  Team team(&harel);
  
  smart_team.add(&giladi);
  smart_team.add(&young_harel);
  smart_team.add(&trained_harel);
  smart_team.add(&hg);
  smart_team.add(&old_harel);
  team.add(&giladi);
  team.add(&hg);
  team.add(&old_harel);
  team.add(&trained_harel);
  team.add(&young_harel);

  while(team.stillAlive()&&smart_team.stillAlive()){
    smart_team.attack(&team);
    if(team.stillAlive())
      team.attack(&smart_team);
  }
  CHECK(smart_team.stillAlive());
  CHECK_FALSE(team.stillAlive());
}


