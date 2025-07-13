#pragma once
#include "SpecialEvent.h"
#include "../Players/Player.h"

class PotionsMerchant: public SpecialEvent {
    friend class Charactor;
    friend class Player;

public:
    PotionsMerchant();


   std:: string getDescription() const override;
     void applyEventP(std::shared_ptr<Player>player) override;
    //void applyEvent(std::shared_ptr<Charactor> charactor) override;
  };
