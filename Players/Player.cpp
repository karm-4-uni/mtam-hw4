
#include  "Player.h"

#include <stdexcept>
#include "Player.h"
#include "Jobs/Magician .h"
#include "Jobs/Warrior.h"
#include "Behiviors/RiskTaking.h"
#include "Behiviors/Responsible.h"
#include <stdexcept>
#include <utility>

#include "Event.h"
#include "Jobs/Archer.h"

int Player::numberofplayers = 0 ;
string Player::getName() const {
   return  this->charactor->getName();
}


Charactor& Player::getCharator() {
   return *this->charactor.get();
}
const Charactor& Player::getCharator() const {
   return *this->charactor.get();
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
return this->charactor.get()->getDescription();
}

Player::Player(const std::string& name
   , const std::string& jobName,
  const std::string& behaviorName,
               int health,
               int coin,
               int force
               )
    : name(name),
playernumber(numberofplayers++),
      charactor(std::make_unique<Charactor>(
          name,
          jobName,
          behaviorName,
          health,
          coin,
          force
      ))
{}

const bool Player::isfullhp() const {
   return this->charactor->isfullhp();
}
//
// Player::Player(std::string name,
//    std::unique_ptr<Charactor> charactor, Stat status) :
// playernumber(numberofplayers++) {
//    this->name = name;
//    this->charactor = std::move(charactor);
//    this->status = status;
//
// }


const int Player::getplayerID() const {
   return playernumber;
}


void Player::doEvent(Event& event) {
this->charactor.get()->doEvent(event);
   isDead() ;

}


bool Player::operator>(const Player &other) const {
   if(this->charactor == other.charactor) {
      if(this->name == other.name) {
         throw std::out_of_range("A player has the same artuibut");
      } else {
         if(this->name > other.name) {
            return  true;
         } else { return  false ;}
      }
   } else {
      return (this->charactor >= other.charactor );
   }
}

bool operator<(const Player &thisplayer, const Player &other) {
   return  (other > thisplayer);
}


bool Player::isDead()  {
 if(this->charactor->getHealthPoints() <= 0 ) {
    this->status = Stat::Dead ;return  true;
 }
   return  false ;
}
void Player::Encounter(std::shared_ptr<Enemy> enemy) {

}
void Player::doBehivior() {
   this->charactor.get()
}
