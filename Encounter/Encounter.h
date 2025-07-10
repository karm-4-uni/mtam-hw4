

#include "../Events/Event.h"

#include "Enemy.h"

class Encounter :  public Event {

    Encounter();
    std::shared_ptr<Enemy> enemy;
Encounter(std::shared_ptr<Enemy> enemy);

virtual string getDescription() const override;
    virtual Player& applyEvent(Player &currPlayer) override ;
};


