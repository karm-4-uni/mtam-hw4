//
// Created by Admin on 05/07/2025.
//
#include <stdexcept>

#include "Player.h"
#include "Utilities.h"
#include  "Behiviors/Responsible.h"
#include "Behiviors/RiskTaking.h"
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
void Behivior::PotionsMerchant(Player& player) {
    //nothing
}
void Responsible::PotionsMerchant(Player& player) {
    if(player.getCharator().getHealthPoints() < 50  ) {
       int coins = player.getCoins();
        int hp = player.getHealthPoints();
        if(coins > PostinCost) {
            player.getCharator().setCoins(coins - PostinCost);
            player.getCharator().setHealthPoints(hp + 10);
            getPotionsPurchaseMessage(player,1);
        }

    }
}
void Risktaking::PotionsMerchant(Player& player) {
    int count = 0 ;
    int coins = player.getCoins();
    int hp = player.getHealthPoints();
    while (player.getCoins() > PostinCost && player.isfullhp() ) {
        player.getCharator().setCoins(coins - PostinCost);
        coins-= PostinCost ;
        hp+= 10 ;
        player.getCharator().setHealthPoints(hp);
        count++;
    }
    getPotionsPurchaseMessage(player,count);

}

std::unique_ptr<Behivior> Behivior::fromString(const std::string& name) {
    if (name == "Responsible")   return std::make_unique<Responsible>();
    if (name == "Risktaking") return std::make_unique<Risktaking>();
    throw std::invalid_argument("Unknown behavior: " + name);
}