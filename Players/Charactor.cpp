//
// Created by Admin on 05/07/2025.
//
#include "Charactor.h"

#include <stdexcept>

#include "Behiviors/Behivior.h"
#include "Jobs/Job.h"

int Charactor::getCoins() const {
    return this->coin;
}
int Charactor::getForce() const {
    return this->force;
}
int Charactor::getLevel() const {
    return this->Level;
}
std::string Charactor::getName() const {
    return this->name;
}
int Charactor::getHealthPoints() const {
    return this->CurrentHP;
}
const int Charactor::getMaxHP() const {
    return this->maxHP;
}
void Charactor::setCoins(int gainedCoin) {
    this->coin = gainedCoin ;
}
void Charactor::setForce(int newForce) {
    this->force = newForce ;
}
void Charactor::setHealthPoints(int gainedhealth) {
    this->CurrentHP = gainedhealth;
}

void Charactor::setLevel(int newLevel) {
    this->Level = newLevel ;
}
const Job& Charactor::getJop() const {
    return   *this->job.get();
}

std::string Charactor::getDescription() const {
    std::string description = "";
    description+= this->name;
    description+=",";
    description+= job->getjob();
    description+= " with ";
    description+= behivior->getBehivior();
    description+=" character (lecel ";
    description+=Level;
    description+=",force ";
    description+= force;
    return description;
}



void valiadation(std::string name , int force,
    int hp,
    int coin) {
    if (name.length() > 15) {
        throw std::invalid_argument("Name must be 15 characters or fewer.");
    }
    if (force <= 0) {throw std::invalid_argument("Force must be positive.");}
    if (hp <= 0 || hp <= 0) {
        throw std::invalid_argument("HP and MaxHP must be positive.");
    }
    if (coin < 0) { throw std::invalid_argument("Coin cannot be negative.") ;}


}

Charactor::Charactor(std::string name,
                     const Job& jobRef,
                     const Behivior& behaviorRef,
                     int force,
                     int hp,
                     int coin)
    : name(std::move(name)),
      Level(1),
      CurrentHP(hp),
      maxHP(hp),
      job(std::make_unique<Job>(jobRef)),
      behivior(std::make_unique<Behivior>(behaviorRef)),
      coin(coin),
      force(force)
{
    valiadation(this->name, force, hp, coin);
}


const bool Charactor::isfullhp() const {
    return (this->getHealthPoints() == maxHP);
}
