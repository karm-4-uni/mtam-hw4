# pragma once

# include <queue>
# include "../Players/Player.h"
# include <vector>
# include "../Rounds/Turns/Turn.h"
# include <memory>
class Round {
static int turnNumber;
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