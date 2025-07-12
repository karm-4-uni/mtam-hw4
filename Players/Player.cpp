
#include  "Player.h"

#include <stdexcept>
#include "Player.h"
#include "Jobs/Magician .h"
#include "Jobs/Warrior.h"
#include "Behiviors/RiskTaking.h"
#include "Behiviors/Responsible.h"
#include <stdexcept>
#include <utility>
#include <memory>
#include "../Events/Event.h"
#include "Jobs/Archer.h"

string Player::getName() const {
   return  this->charactor->getName();
}


Charactor& Player::getCharator() {
   return *charactor;
}
const Charactor& Player::getCharator() const {
   return *charactor;  // or charactor.get()
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

Player::Player(const std::string& name,
               const std::string& job,
               const std::string& behavior,
               int health,
               int coin,
               int force,
               int playercount)
  : name(name),
    charactor(std::make_shared<Charactor>(name, job, behavior, health, coin, force)),
    status(Stat::Alive),
    playernumber(playercount)
{  }

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


void Player::doEvent(std::shared_ptr<Event> event) {

     event.operator*().applyEventP(shared_from_this());

}

void Player::doBehivior()
{
}

bool Player::isDead()  {
   if(this->charactor->getHealthPoints() <= 0 ) {
      this->status = Stat::Dead ;return  true;
   }
   return  false ;
}
bool Player::operator>=(const Player &other) const {
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
bool operator<=(const Player &thisplayer, const Player &other) {
   return  (other >= thisplayer);
}
