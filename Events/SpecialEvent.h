


#include "Event.h"

class SpecialEvent : Event {


    virtual string getDescription() const override;
    virtual Player &applyEvent(Player &currPlayer) override;
};
