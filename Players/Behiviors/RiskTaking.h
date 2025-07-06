//
// Created by Admin on 05/07/2025.
//

#ifndef RISKTAKING_H
#define RISKTAKING_H

#endif //RISKTAKING_H
 class Risktaking : public Behivior {
 protected:
     const std::string getBehivior() const override ;
     void PotionsMerchant(Player& player) override ;
 public:
     Risktaking() = default;
 };