

#include "SolarEclipse.h"


#include "../Players/Player.h"

#include "SpecialEvent.h"
string SolarEclipse::getDescription() const {
    return getname();

}

    void SolarEclipse::applyEventP(std::shared_ptr<Player> player) {
    auto& job = *player->getCharator().getjob();
    job.applyin(player, shared_from_this())
    }

