


#include "Encounter.h"

#include <memory>

#include "Enemy.h"
Encounter::Encounter() {

}
Encounter::Encounter(std::shared_ptr<Enemy> e) : enemy(std::move(e)) {}


std::string Encounter::getDescription() const {

  return this->enemy->getdescription();

 }
void Encounter:: applyEventP(std::shared_ptr<Player>player) {
    auto& job = *player->getCharator().getjob();
    job.applyin(player, shared_from_this());

 }

