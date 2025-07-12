
#pragma once
#include "Event.h"
class Enemy;

class Charactor;
class Player;
class Encounter :  public Event {
public:
    Encounter();
    std::shared_ptr<Enemy> enemy;
    Encounter(std::shared_ptr<Enemy> enemy);
    std::shared_ptr<Enemy> getEnemy() const {
        return enemy;
    }
    std::string getDescription() const override;
    void applyEventP(std::shared_ptr<Player>player) override ;
};
