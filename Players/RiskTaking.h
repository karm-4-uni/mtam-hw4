//
// Created by Admin on 05/07/2025.
//
#pragma once

#include "Behivior.h"

class Risktaking : public Behivior {
 protected:
     const std::string getBehivior() const override ;
     void PotionsMerchant(std::shared_ptr<Player>player) override ;
     //void PotionsMerchantC(std::shared_ptr<Charactor> charactor)  override;
 public:
     Risktaking() = default;
     ~Risktaking()  = default;
 };

