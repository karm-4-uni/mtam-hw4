
#include "PotionsMerchant.h"


PotionsMerchant::PotionsMerchant(): SpecialEvent("PotionsMerchant") {

}


std::string PotionsMerchant::getDescription() const {

    return getname();

}
void PotionsMerchant:: applyEventP(std::shared_ptr<Player>player) {
    player.operator*().getCharator().operator*().get_behivior().operator*().PotionsMerchant(player);

}
