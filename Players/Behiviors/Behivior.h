//
// Created by Admin on 05/07/2025.
//

#ifndef BEHIVIOR_H
#define BEHIVIOR_H
#include <memory>
#include <string>
class Player;
#endif //BEHIVIOR_H
class Charactor;
#pragma once
class PotionsMerchant;
class Behivior {
     friend  class  Charactor;
friend class PotionsMerchant;
protected:



    virtual  const std::string getBehivior() const ;
    virtual void PotionsMerchant(std::shared_ptr<Player>player) =0 ;

    static std::unique_ptr<Behivior> fromString(const std::string& name);
public:
     Behivior() = default;
~Behivior()  = default;

};
