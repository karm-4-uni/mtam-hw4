

#include "SolarEclipse.h"


#include "../Players/Player.h"

#include "SpecialEvent.h"
string SolarEclipse::getDescription() const {
    return getname();

}

    void SolarEclipse::applyEventP(std::shared_ptr<Player> player) {
    player->getCharator().operator*().getjob()->applyin(player);

    }

