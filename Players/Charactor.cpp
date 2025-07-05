//
// Created by Admin on 05/07/2025.
//
#include "Charactor.h"
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
    return   *this->jop.get();
}

std::string Charactor::getDescription() const {
    std::string description = "";
    description+= this->name;
    description+=",";
    description+= jop->getjob();
    description+= " with ";
    description+= behivior->getBehivior();
    description+=" character (lecel ";
    description+=Level;
    description+=",force ";
    description+= force;
    return description;
}




