//
// Created by Admin on 05/07/2025.
//

#ifndef BEHIVIOR_H
#define BEHIVIOR_H
#include <string>
class Player;
#endif //BEHIVIOR_H
class Charactor;

class Behivior {
    friend  class  Charactor;
protected:
    virtual  const std::string getBehivior() const ;
    virtual void PotionsMerchant(Player& player) ;
};
