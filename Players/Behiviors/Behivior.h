//
// Created by Admin on 05/07/2025.
//

#pragma once
#include <memory>
#include <string>
class Player;
class Charactor;
#pragma once
class PotionsMerchant;
class Behivior {
     friend  class  Charactor;
friend class PotionsMerchant;
protected:



    virtual  const std::string getBehivior() const ;
    virtual void PotionsMerchant(Player& player)  ;
    virtual void PotionsMerchant(std::shared_ptr<Player>player) ;
 //   virtual void PotionsMerchantC(std::shared_ptr<Charactor> charactor) =0 ;
    static std::unique_ptr<Behivior> fromString(const std::string& name);
public:
     Behivior() = default;
~Behivior()  = default;

};
