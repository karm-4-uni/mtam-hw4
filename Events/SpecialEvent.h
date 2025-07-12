#pragma once
#include <memory>
#include <string>

#include "Event.h"

class SpecialEvent : public Event {
    friend class Charactor;
    friend class Player;

public:
SpecialEvent();
    SpecialEvent(const std::string& name );

    virtual std::string getDescription() const =0;
   // virtual void applyEvent(std::shared_ptr<Charactor>charactor) =0;
    virtual void applyEventP(std::shared_ptr<Player>player) =0;
};
