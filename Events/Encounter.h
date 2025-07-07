

#include "Event.h"

#include "Enemy/Enemy.h"

class Encounter : Event {

    std::shared_ptr<Enemy> enemy;


virtual string getDescription() const override;
    virtual Player& applyEvent(Player &currPlayer) override ;
};


