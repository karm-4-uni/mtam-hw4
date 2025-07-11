# pragma once

# include <queue>
# include "../Players/Player.h"
# include "../Turns/Turn.h"
# include <memory>
#include "../Utilities.h"
class Round {
friend  class  Turn;
std::shared_ptr<std::queue<std:: shared_ptr<Player>>>players;
    std::shared_ptr<std::queue<std::shared_ptr<Event>>> events;
     int RoundNum;
   // std::vector<std::shared_ptr<Turn>> turns;
public:
Round();
Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers,
    std::shared_ptr<std::queue<std::shared_ptr<Event>>>events);
    ~Round();
    void startRound();
    void applayturns();
    void checkPlayers();

};