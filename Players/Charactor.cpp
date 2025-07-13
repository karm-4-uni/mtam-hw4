//
// Created by Admin on 05/07/2025.
//
//
// Created by Admin on 05/07/2025.
//

#include <stdexcept>
# include "Charactor.h"

#include <ostream>

#include "../Events/Event.h"
#include "Behivior.h"
#include "Job.h"

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
        if(gainedhealth<0) {
            this->CurrentHP=0;
        } else {
            this->CurrentHP = gainedhealth;
        }

    }

void Charactor::setLevel(int newLevel) {
    this->Level = newLevel ;
}

const std::shared_ptr<Job> &Charactor::getJop() const {
    return  this->job;
}

std::string Charactor::getDescription() const {
    std::string description = "";
    description+= this->name;
    description+=", ";
    description+= job->getjob();
    description+= " with ";
    description+= behivior->getBehivior();
    description+=" character (level ";
    description+= std::to_string(Level)  ;
    description+=", force ";
        description+= std::to_string((force) )  ;
    description+= ")";
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
                     std::string jobName,
                     std::string behaviorName,
                     int hp,
                     int coin,
                     int force)
  : name(std::move(name)),
    Level(1),
    CurrentHP(hp),
    maxHP(hp),
    job(Job::fromString(jobName)),
    behivior(Behivior::fromString(behaviorName)),
    coin(coin),
    force(force)
{
    valiadation(this->name, force, hp, coin);
}


const bool Charactor::isfullhp() const {
    return (this->getHealthPoints() == maxHP);
}
void Charactor::doJob() {
    this->job.get()->doJob(*this);
}



bool Charactor::operator>=(const Charactor &other) const {
        if (Level != other.Level)
            return Level > other.Level;
        if (coin != other.coin)
            return coin > other.coin;
        return name > other.name;
}

bool Charactor::operator==(const Charactor &other) const {
    if(this->Level == other.Level
        && this->coin == other.coin
        && this->name == other.name) {
        return true;
    } return  false ;
}


bool operator<=(const Charactor& currntChar ,const Charactor &other) {
    return  (other  >= currntChar);
}
//
// void Charactor::doBehivior() {
//
//         charactor->get_behivior()->PotionsMerchant(shared_from_this());
//
// }

void Charactor::takeDamge(std::shared_ptr<Enemy> enemy) {

}

int Charactor::getcombatpower() {
    if(this->job->getjob() == "Warrior") {
        return  this->force * 2 + this->Level ;
    } else {
        return this->force + this->Level ;
    }
}
