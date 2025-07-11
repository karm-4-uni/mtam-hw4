

#include "../Events/Event.h"

#include "Enemy.h"

class Encounter :  public Event {

    Encounter();
    std::shared_ptr<Enemy> enemy;
Encounter(std::shared_ptr<Enemy> enemy);

std::string getDescription() const override;
    virtual void applyEvent(Charactor &charactor) override ;
};


