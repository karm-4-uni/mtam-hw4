

#include "SolarEclipse.h"


#include "../Players/Player.h"

#include "SpecialEvent.h"
string SolarEclipse::getDescription() const {
    return getname();

}

    void SolarEclipse::applyEventP(std::shared_ptr<Player> player) {
    auto self = std::static_pointer_cast<SolarEclipse>(shared_from_this());
    player.get()->getCharator().getjob()->applyin(player, self);

    }

