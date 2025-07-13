#include <iostream>
#include <stdexcept>
#include "../../Events/Encounter.h"
#include "Archer.h"
#include "Magician .h"
#include "../Charactor.h"
#include "Warrior.h"
#include "../../Utilities.h"

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
charactor.maxHP += 50 ;
    charactor.CurrentHP += 50 ;
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



void Warrior::applyin(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
    Charactor& charct = player->getCharator();
    if(charct.getcombatpower()>
     enemy->getcobatpower()){
        charct.setCoins(charct.getCoins()+enemy->getloot());
        charct.setLevel(charct.getLevel()+1);
     std::cout <<   getEncounterWonMessage(*player,enemy.operator*().getloot());
        charct.setHealthPoints(charct.getHealthPoints()-enemy->getdamge());
     }else {
         charct.setHealthPoints(charct.getHealthPoints()-enemy->getdamge());
       std::cout <<  getEncounterLostMessage(*player,enemy.operator*().getdamge());
     }
}
void Warrior::applyin(std::shared_ptr<Player> player ) {
    player.operator*().getCharator().force-=1;
  std::cout <<   getSolarEclipseMessage(*player,-1);

}

void Archer::applyin(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
    Charactor& charct = player->getCharator();
    if(charct.getcombatpower()>
     enemy->getcobatpower()){
        charct.setCoins(charct.getCoins()+enemy->getloot());
        charct.setLevel(charct.getLevel()+1);
     std::cout <<   getEncounterWonMessage(*player,enemy.operator*().getloot());

     }else {
         charct.setHealthPoints(charct.getHealthPoints()-enemy->getdamge());
       std::cout <<  getEncounterLostMessage(*player,enemy.operator*().getdamge());
     }
}
void Archer::applyin(std::shared_ptr<Player> player) {

    player.operator*().getCharator().force-=1;
 std::cout <<   getSolarEclipseMessage(*player,-1);

}
void Magician::applyin(std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy) {
    Charactor& charct = player->getCharator();
    if(charct.getcombatpower()>
     enemy->getcobatpower()){
        charct.setCoins(charct.getCoins()+enemy->getloot());
        charct.setLevel(charct.getLevel()+1);
    std::cout <<    getEncounterWonMessage(*player,enemy.operator*().getloot());

     }else {
         charct.setHealthPoints(charct.getHealthPoints()-enemy->getdamge());
      std::cout <<   getEncounterLostMessage(*player,enemy.operator*().getdamge());
     }

}
void Magician::applyin(std::shared_ptr<Player> player) {
    player.operator*().getCharator().force+=1;
 std::cout <<  getSolarEclipseMessage(*player,1);

}





