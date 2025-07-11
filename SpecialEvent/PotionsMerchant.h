
#include "SpecialEvent.h"

class PotionsMerchant: public SpecialEvent{

    PotionsMerchant();

   std:: string getDescription() const override;
     void applyEvent(std::shared_ptr<Charactor>charactor) override;
  };
