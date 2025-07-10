
#pragma once

#include "../Players/Player.h"


class Event {

protected:
 string name;
public:
    virtual ~Event() = default;
     Event()=default;
 Event(const std::string& name);
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
   virtual  string getDescription() const=0;
    virtual  Player& applyEvent(Player& currPlayer)=0;
public:
 std::string getname() const;

};
