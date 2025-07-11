# pragma once



#include "../Events/Event.h"

class SpecialEvent : public Event {

public:
SpecialEvent();
    SpecialEvent(const std::string& name );

    virtual string getDescription() const =0;
    virtual void applyEvent(std::shared_ptr<Charactor>charactor) =0;
};
