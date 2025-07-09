
#pragma once

#include "../Players/Player.h"

class Event {

public:
    virtual ~Event() = default;
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
   virtual  string getDescription() const=0;
    virtual  Player& applyEvent(Player& currPlayer);


};
