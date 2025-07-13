# pragma once


# include "../../Players/Player.h"
# include "../../Events/Event.h"
# include <memory>
class Turn {
    int turnnumber;
public:
    std::shared_ptr<Player> currPlayer;
    std::shared_ptr<Event> currEvent;


    Turn();
    Turn(std::shared_ptr<Player> currPlayer,    std::shared_ptr<Event> currEvent , int turnnumber);
    ~Turn();
    void applyTurn();
    //const std::string printTurnoutcome() ;
};