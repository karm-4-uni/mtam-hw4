#include  "Player.h"

#include <stdexcept>
#include "Player.h"
#include "Jobs/Magician .h"
#include "Jobs/Warrior.h"
#include "Behiviors/RiskTaking.h"
#include "Behiviors/Responsible.h"
#include <stdexcept>
#include <utility>

#include "Jobs/Archer.h"

string Player::getName() const {
   return  this->charactor->getName();
}


Charactor &Player::getCharator() {
   return this->getCharator();
}
const Charactor &Player::getCharator() const {
   return this->getCharator();
}
int Player::getCoins() const {
   return this->charactor->getCoins();
}
int Player::getForce() const {
   return charactor->getForce();
}
int Player::getLevel() const {
   return  charactor->getLevel() ;
}
int Player::getHealthPoints() const {
   return charactor->getHealthPoints();
}
string Player::getDescription() const {

}

Player::Player(std::string name,
               int health,
               int coin,
               int force,
               std::string jobName,
               std::string behaviorName)
    : name(std::move(name)),
      charactor(std::make_unique<Charactor>(
          name,
          jobName,
          behaviorName,
          force,
          health,
          coin
      ))
{}

const bool Player::isfullhp() const {
   return this->charactor->isfullhp();
}

Player::Player(std::string name,
   std::unique_ptr<Charactor> charactor, Stat status) {
   this->name = name;
   this->charactor = std::move(charactor);
   this->status = status;
}
