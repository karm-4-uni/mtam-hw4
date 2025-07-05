# pragma once

# include <queue>
# include "Player.h"
# include <vector>
# include "Turns/Turn.h"
# include <memory>
class Round {

std::shared_ptr<std::queue<std::shared_ptr<Player>>>players;
     int RoundNum;
    std::vector<std::shared_ptr<Turn>> turns;
public:
Round();
Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers){

    players =otherplayers;
    this->RoundNum=1;
    for(int i=0;i<this->players->size();i++) {
turns.push_back(std::make_shared<Turn>());
    }
    }



};