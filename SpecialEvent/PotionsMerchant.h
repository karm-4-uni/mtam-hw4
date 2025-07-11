
#include "SpecialEvent.h"
#include "../Players/Player.h"

class PotionsMerchant: public SpecialEvent{

    PotionsMerchant();

   std:: string getDescription() const override;
     Player& applyEvent(Player& currPlayer) override;
  };
