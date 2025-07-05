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

}




