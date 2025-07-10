

#include "Encounter.h"


Encounter::Encounter() {

}

Encounter::Encounter(std::shared_ptr<Enemy> enemy) {

 this->enemy = std::move(enemy);

}



 string Encounter::getDescription() const {

  return this->enemy->getdescription();

 }
Player& Encounter:: applyEvent(Player &currPlayer) {


 }

