
#include "PotionsMerchant.h"


PotionsMerchant::PotionsMerchant(): SpecialEvent("PotionsMerchant") {

}


string PotionsMerchant::getDescription() const {

    return getname();

}
void PotionsMerchant:: applyEvent(std::shared_ptr<Charactor>charactor) {




}