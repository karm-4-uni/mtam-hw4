//
// Created by Admin on 05/07/2025.
//

#include <stdexcept>

#include "Archer.h"
#include "Magician .h"
#include "Charactor.h"
#include "Jobs/Job.h"
#include "Warrior.h"
void Job::doJob(Charactor& charactor) {
// nothing
}
void Magician::doJob(Charactor& charactor) {
    // nothing
}

void Archer::doJob(Charactor& charactor) {
    int newCoin = charactor.getCoins() +  10;
    charactor.setCoins(newCoin);
}
void Warrior::doJob(Charactor& charactor) {
    int newForce = charactor.getForce() * 2 +  charactor.getLevel();
    charactor.setForce(newForce);
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
const std::string Warrior::getjob() const {
    return  "Warrior";
}



void Job::SolarEclipse(Charactor &charactor) {
    //NOTHING
}

void Warrior::SolarEclipse(Charactor &charactor) {
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

Job::Job() {
    //Nothing
}

Warrior::Warrior() : Job(){
}
Archer::Archer() : Job(){

}
Magician::Magician() : Job() {

}
std::unique_ptr<Job> Job::fromString(const std::string &name) {
     if (name == "Warrior") {return std::make_unique<Warrior>();}
    if (name == "Magician")   { return std::make_unique<Magician>();}
    if ( name == "Archer") { return  std::make_unique<Archer>();}
    throw std::invalid_argument("Unknown job: " + name);
}



