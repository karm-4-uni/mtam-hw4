#pragma once
#include "Player.h"

# include "memory"
class Enemy {
int loot;
    int combatPower;
    int damge;

public:
    Enemy();
    virtual void attack(std::shared_ptr<Player>);


};

class Snail : Enemy {

     void  attack(std::shared_ptr<Player>) override;
};

class Slime : Enemy {

    void attack(std::shared_ptr<Player>) override;
};

class Barlog : Enemy {
void attack(std::shared_ptr<Player>) override;
};