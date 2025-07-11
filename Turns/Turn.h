# pragma once

#include  "../Utilities.h"
# include "../Players/Player.h"
# include "../Events/Event.h"
# include <memory>
class Turn {
public:
    std::shared_ptr<Player> currPlayer;
    std::shared_ptr<Event> currEvent;


    Turn();
    Turn(std::shared_ptr<Player> currPlayer,    std::shared_ptr<Event> currEvent);
    ~Turn();
void applyTurn();
void printdetail() const;

};