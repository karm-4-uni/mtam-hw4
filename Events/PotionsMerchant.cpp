
#include "PotionsMerchant.h"


PotionsMerchant::PotionsMerchant(): SpecialEvent("PotionsMerchant") {

}


std::string PotionsMerchant::getDescription() const {

    return getname();

}
void PotionsMerchant:: applyEventP(std::shared_ptr<Player>player) {
    player ->getCharator().get_behivior()->PotionsMerchant(player);

}