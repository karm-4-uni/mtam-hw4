


#include <string>

#include "Event.h"

class Charactor;

class SpecialEvent : Event {


    virtual std::string getDescription() const override;
    virtual void applyEvent(Charactor &charactor) override;
};
