
#include <stdexcept>

#include "Responsible.h"
#include "RiskTaking.h"
#include "Player.h"
#include "Behivior.h"

#include <iostream>

#include "../Utilities.h"
const int PostinCost = 5 ;
const std::string Behivior::getBehivior() const {
    return "defult";
}
const std::string Responsible::getBehivior() const {
    return "Responsible";
}
const std::string Risktaking::getBehivior() const {
    return "Risktaking";
}
void Behivior::PotionsMerchant(std::shared_ptr<Player>player) {
    //nothing
}
void Risktaking::PotionsMerchant(std::shared_ptr<Player>player) {
  int didhebuy= 0;
    if(player.operator*().getCharator().getHealthPoints() < 50  ) {
        int coins = player.operator*().getCoins();
        int hp = player.operator*().getHealthPoints();
        if(coins > PostinCost) {
            player.operator*().getCharator().setCoins(coins - PostinCost);
            player.operator*().getCharator().setHealthPoints(hp + 10);
            didhebuy++ ;
            //   getPotionsPurchaseMessage(player,1);
        }

    }std::cout << getPotionsPurchaseMessage(*player,didhebuy);
}
void Responsible::PotionsMerchant(std::shared_ptr<Player>player) {
    int count = 0 ;
    int coins = player.operator*().getCoins();
    int hp = player.operator*().getHealthPoints();
    while (player.operator*().getCoins() > PostinCost && !player.operator*().isfullhp() ) {
        player.operator*().getCharator().setCoins(coins - PostinCost);
        coins-= PostinCost ;
        hp+= 10 ;
        player.operator*().getCharator().setHealthPoints(hp);
        count++;
    }
  std::cout <<   getPotionsPurchaseMessage(*player,count);

}

std::unique_ptr<Behivior> Behivior::fromString(const std::string& name) {
    if (name == "Responsible") {  return std::make_unique<Responsible>();}
    if (name == "RiskTaking") {return std::make_unique<Risktaking>();}
    throw std::invalid_argument("Unknown behavior: " + name);
}

void Behivior::PotionsMerchant(Player& player) {
    // do nothing
}
