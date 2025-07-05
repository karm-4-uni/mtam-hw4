# pragma once

# include <queue>
# include "Player.h"
# include <vector>
# include "Turns/Turn.h"
# include <memory>
class Round {

std::shared_ptr<std::queue<std::shared_ptr<Player>>>players;
     int RoundNum;
    std::vector<std::unique_ptr<Turn>> turns;

Round();
Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers){

    players =otherplayers;
    this->RoundNum=1;
    }



};