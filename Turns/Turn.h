# pragma once


# include "Player.h"
# include "Events/Event.h"
# include <memory>
class Turn {
    std::shared_ptr<Player> currPlayer;
    std::shared_ptr<Event> currEvent;


    Turn();
    Turn(std::shared_ptr<Player> currPlayer,    std::shared_ptr<Event> currEvent);
void applyTurn(Player& player);


};