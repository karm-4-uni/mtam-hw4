//
// Created by Admin on 05/07/2025.
//

#ifndef RESPONSIBLE_H
#define RESPONSIBLE_H
#include "Behivior.h"

#endif //RESPONSIBLE_H
class Responsible : public Behivior {
protected:

    const std::string getBehivior() const override ;
    void PotionsMerchant(std::shared_ptr<Player>player) override  ;
public:
    Responsible() = default ;
    ~Responsible()  = default;
};