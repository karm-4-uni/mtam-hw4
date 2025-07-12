//
// Created by Admin on 05/07/2025.
//

#include <stdexcept>
#include "../../Events/Encounter.h"
#include "Archer.h"
#include "Magician .h"
#include "../Charactor.h"
#include "Warrior.h"
#include "../../Utilities.h"

#include <stdexcept>

#include "Archer.h"
#include "Magician .h"
#include "../Charactor.h"
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

std::shared_ptr<Job> Job::fromString(const std::string &name) {
     if (name == "Warrior") {return std::make_shared<Warrior>();}
    if (name == "Magician")   { return std::make_shared<Magician>();}
    if ( name == "Archer") { return  std::make_shared<Archer>();}
    throw std::invalid_argument("Unknown job: " + name);
}



void Warrior::applyin(std::shared_ptr<Player> player, std::shared_ptr<Encounter> encounter) {
    if(player.operator*().getCharator().getcombatpower()>
        encounter.operator*().getEnemy().operator*().getcobatpower()){
        player.operator*().getCharator().coin+=encounter.operator*().getEnemy().operator*().getloot();
        player.operator*().getCharator().Level++;
        getEncounterWonMessage(*player,encounter.operator*().getEnemy().operator*().getloot());
        }else {
            player.operator*().getCharator().CurrentHP-=encounter.operator*().getEnemy().operator*().getdamge();
            getEncounterLostMessage(*player,encounter.operator*().getEnemy().operator*().getdamge());
        }
}
void Warrior::applyin(std::shared_ptr<Player> player, std::shared_ptr<::SolarEclipse> solar) {
    player.operator*().getCharator().force-=1;
    getSolarEclipseMessage(*player,-1);

}

void Archer::applyin(std::shared_ptr<Player> player, std::shared_ptr<Encounter> encounter) {
if(player.operator*().getCharator().getcombatpower()>
    encounter.operator*().getEnemy().operator*().getcobatpower()){
player.operator*().getCharator().coin+=encounter.operator*().getEnemy().operator*().getloot();
    player.operator*().getCharator().Level++;
    getEncounterWonMessage(*player,encounter.operator*().getEnemy().operator*().getloot());
    player.operator*().getCharator().CurrentHP-=encounter.operator*().getEnemy().operator*().getdamge();

}else {
    player.operator*().getCharator().CurrentHP-=encounter.operator*().getEnemy().operator*().getdamge();
    getEncounterLostMessage(*player,encounter.operator*().getEnemy().operator*().getdamge());
}
}
void Archer::applyin(std::shared_ptr<Player> player, std::shared_ptr<::SolarEclipse> solar) {

    player.operator*().getCharator().force-=1;
    getSolarEclipseMessage(*player,-1);

}
void Magician::applyin(std::shared_ptr<Player> player, std::shared_ptr<Encounter> encounter) {
    if(player.operator*().getCharator().getcombatpower()>
        encounter.operator*().getEnemy().operator*().getcobatpower()){
        player.operator*().getCharator().coin+=encounter.operator*().getEnemy().operator*().getloot();
        player.operator*().getCharator().Level++;
        getEncounterWonMessage(*player,encounter.operator*().getEnemy().operator*().getloot());
        }else {
            player.operator*().getCharator().CurrentHP-=encounter.operator*().getEnemy().operator*().getdamge();
            getEncounterLostMessage(*player,encounter.operator*().getEnemy().operator*().getdamge());
        }

}
void Magician::applyin(std::shared_ptr<Player> player, std::shared_ptr<::SolarEclipse> solar) {
    player.operator*().getCharator().force+=1;
    getSolarEclipseMessage(*player,1);

}

void Job::applyin(std::shared_ptr<Player> player, std::shared_ptr<Encounter> encounter) {

}
void Job::applyin(std::shared_ptr<Player> player, std::shared_ptr<::SolarEclipse> solar) {

}

