#pragma once

#include "SpecialEvent.h"
#include "../Players/Player.h"

class PotionsMerchant: public SpecialEvent{
public:
    PotionsMerchant();

   std:: string getDescription() const override;
     void applyEvent(std::shared_ptr<Player>player) override;
  };
