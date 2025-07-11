# pragma once
#include "../Players/Player.h"



#include "../Events/Event.h"

class SpecialEvent : public Event {

public:
SpecialEvent();
    SpecialEvent(const std::string& name );

    virtual string getDescription() const =0;
    virtual Player &applyEvent(Player &currPlayer) =0;
};
