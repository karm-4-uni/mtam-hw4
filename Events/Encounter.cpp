


#include "Encounter.h"

#include <memory>

#include "Enemy.h"
#include "Encounter.h"


Encounter::Encounter() {

}

Encounter::Encounter(std::shared_ptr<Enemy> enemy) {

    this->enemy = std::move(enemy);

}



string Encounter::getDescription() const {

    return this->enemy->getdescription();

}
void Encounter:: applyEventP(std::shared_ptr<Player>player) {
    player->getCharator().getjob().operator*().applyin(player,this->enemy);


}
