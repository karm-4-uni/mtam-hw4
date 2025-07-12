
#include <stdexcept>

#include "Responsible.h"
#include "RiskTaking.h"
#include "../Player.h"
#include "Behivior.h"
#include "../../Utilities.h"
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
    bool didhebuy=false;
    if(player.operator*().getCharator().operator*().getHealthPoints() < 50  ) {
        int coins = player.operator*().getCoins();
        int hp = player.operator*().getHealthPoints();
        if(coins > PostinCost) {
            player.operator*().getCharator().operator*().setCoins(coins - PostinCost);
            player.operator*().getCharator().operator*().setHealthPoints(hp + 10);
            didhebuy=true;
            //   getPotionsPurchaseMessage(player,1);
        }
        getPotionsPurchaseMessage(*player,didhebuy);

    }
}
void Responsible::PotionsMerchant(std::shared_ptr<Player>player) {
    int count = 0 ;
    int coins = player.operator*().getCoins();
    int hp = player.operator*().getHealthPoints();
    while (player.operator*().getCoins() > PostinCost && player.operator*().isfullhp() ) {
        player.operator*().getCharator().operator*().setCoins(coins - PostinCost);
        coins-= PostinCost ;
        hp+= 10 ;
        player.operator*().getCharator().operator*().setHealthPoints(hp);
        count++;
    }
    getPotionsPurchaseMessage(*player,count);

}

std::shared_ptr<Behivior> Behivior::fromString(const std::string& name) {
    if (name == "Responsible") {  return std::make_shared<Responsible>();}
    if (name == "Risktaking") {return std::make_shared<Risktaking>();}
    throw std::invalid_argument("Unknown behavior: " + name);
}