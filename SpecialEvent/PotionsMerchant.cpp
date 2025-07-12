
#include "PotionsMerchant.h"


PotionsMerchant::PotionsMerchant(): SpecialEvent("PotionsMerchant") {

}


string PotionsMerchant::getDescription() const {

    return getname();

}
void PotionsMerchant:: applyEvent(std::shared_ptr<Player>player) {
    player.operator*().getCharator().get_behivior().operator*().PotionsMerchant(player);

}