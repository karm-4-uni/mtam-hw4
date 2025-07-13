#include "Enemy.h"

// This actually *defines* and zero‐initializes the static member:
int Barlog::bonusPower = 0;

Barlog::Barlog() {
    this->name="Balrog";
    this->damge=9001;
    this->loot =100;
    this->combatPower=15 + Barlog::bonusPower;
    Barlog::bonusPower+=2;
}
std::shared_ptr<Enemy> Barlog::create() const {
    return std::make_shared<Barlog>();
}


std::string Barlog::getdescription() const {
    std::string g= "Balrog (power "+ std::to_string(combatPower) +", loot "+ std::to_string(loot)+", "
                   "damage "+std::to_string(damge)+ ")";
    return  g;
}