//
// Created by Admin on 05/07/2025.
//
#include "Job.h"
#include "Archer.h"
#include "Magician .h"
#include "Worrior.h"
void Job::doJob(Charactor& charactor) {
// nothing
}
void Magician::doJob(Charactor& charactor) {
    // nothing
}
void Worrior::doJob(Charactor& charactor) {
    int newForce = charactor.getForce() * 2 +  charactor.getLevel();
    charactor.setForce(newForce);
}
void Archer::doJob(Charactor& charactor) {
    int newCoin = charactor.getCoins() +  10;
    charactor.setCpoins(newCoin);
}


const std::string Job::getjob() const {
    return  "Job";
}

const std::string Archer::getjob() const {
    return  "Archer";
}

const std::string Magician::getjob() const {
    return  "Magician";
}

const std::string Worrior::getjob() const {
    return  "Worrior";
}


void Job::SolarEclipse(Charactor &charactor) {
    //NOTHING
}
void Worrior::SolarEclipse(Charactor &charactor) {
    int newForce = charactor.getForce() - 1;
    charactor.setForce(newForce);
}

void Magician::SolarEclipse(Charactor &charactor) {
    int newForce = charactor.getForce() + 1;
    charactor.setForce(newForce);
}
void Archer::SolarEclipse(Charactor &charactor) {
    int newForce = charactor.getForce() - 1;
    charactor.setForce(newForce);
}
