

#include "Event.h"

class Enemy;

class encounter : Event {

    std::shared_ptr<Enemy> enemy;


virtual string getDescription() const override;
    virtual Player &applyEvent(Player &currPlayer) override {


    }
};


