
#include "SpecialEvent.h"

class PotionsMerchant: public SpecialEvent{

    PotionsMerchant();

   std:: string getDescription() const override;
     Player& applyEvent(Player& currPlayer) override;
  };
