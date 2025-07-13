#pragma once

#include <memory>
#include <string>
class Player;
#include "SpecialEvent.h"
class SolarEclipse: public SpecialEvent{
    friend class Charactor;
    friend class Player;

public:
    SolarEclipse():SpecialEvent("SolarEclipse"){}

    std:: string getDescription() const override;
    // void applyEvent(std::shared_ptr<Charactor>charactor) override;
    void applyEventP(std::shared_ptr<Player>player) override;
};




