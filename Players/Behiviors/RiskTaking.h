//
// Created by Admin on 05/07/2025.
//
#pragma once
#ifndef RISKTAKING_H
#define RISKTAKING_H
#include "Behivior.h"

 class Risktaking : public Behivior {
 protected:
     const std::string getBehivior() const override ;
     void PotionsMerchant(Player& player) override ;
 public:
     Risktaking() = default;
 }
;
#endif //RISKTAKING_H