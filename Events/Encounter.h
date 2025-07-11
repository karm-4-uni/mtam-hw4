

#include "Event.h"

#include "Enemy/Enemy.h"

class Encounter : Event {

    std::shared_ptr<Enemy> enemy;


std::string getDescription() const override;
    virtual void applyEvent(Charactor &charactor) override ;
};


