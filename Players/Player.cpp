#include  "Player.h"

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
string descreption = this->name ;
   descreption+= charactor->getJobName();
   descreption+=" with ";
   descreption+= charactor->getBehaviorName() ;
   descreption+= " charactor " ;
   descreption+= "(level ";
   descreption+= charactor->getLevel();
   descreption+= ", force ";
   descreption+= charactor->getForce();
   return  descreption;
}




