#pragma once

# include <memory>
# include <vector>

#include "../Players/Player.h"
class Charactor;
class Player;

class Enemy {
protected:
    std::string name="";
    int loot=0;
    int combatPower=0;
    int damge=0;

public:
    Enemy()= default;
   virtual  ~Enemy() = default;
   int getloot() const  {
       return this->loot;
   }
    int getcobatpower()const {
       return this->combatPower;
   }
    int getdamge()const {
       return this->damge;
   }
    std::string getname() const {
       return this->name;
   }
   virtual std::shared_ptr<Enemy> create() const=0;
virtual std::string getdescription()const =0;
     void attack(std::shared_ptr<Charactor> chara) const {

     }
};

class Snail : public Enemy {
public:
    Snail() {
        this->name="Snail";
        this->damge=10;
        this->loot =2;
        this->combatPower=5;
    }
    std::shared_ptr<Enemy> create() const override {
    return std::make_shared<Snail>();
    }

    std::string getdescription() const override {
        std::string g= "Snail (power "+ std::to_string(combatPower) +", loot "+ std::to_string(loot)+", "
                       "damage "+std::to_string(damge)+ ")";
        return  g;
    }
};

class Slime : public Enemy {
public:
    Slime() {
        this->name="Slime";

        this->damge=25;
        this->loot =5;
        this->combatPower=12;
    }
    std::shared_ptr<Enemy> create() const override
    {
    return std::make_shared<Slime>();    }


    std::string getdescription() const override {
        std::string g= "Slime (power "+ std::to_string(combatPower) +", loot "+ std::to_string(loot)+", "
                       "damage "+std::to_string(damge)+ ")";
        return  g;
    }
};

class Barlog : public Enemy {
public:
    Barlog() {
        this->name="Balrog";
        this->damge=9001;
        this->loot =100;
        this->combatPower=15;
    }
    std::shared_ptr<Enemy> create()  const override {
        return std::make_shared<Barlog>();
    }


    std::string getdescription() const override {
        std::string g= "Balrog (power "+ std::to_string(combatPower) +", loot "+ std::to_string(loot)+", "
                       "damage "+std::to_string(damge)+ ")";
        return  g;
    }
};

    class Pack : public Enemy {
    std::vector<std::shared_ptr<Enemy>> enemies;
        int count ;
public:
        Pack() = default ;
        Pack(const std::vector<std::shared_ptr<Enemy>>& es) : enemies(es), count(0) {
            for (const auto& e : es) {
                this->loot += e->getloot();
                this->damge += e->getdamge();
                this->combatPower += e->getcobatpower();
                ++count;
            }
        }


        void addEnemy(const std::shared_ptr<Enemy>& e) {
        this->loot +=e->getloot();
        this->damge +=e->getdamge();
        this->combatPower +=e->getcobatpower();
        enemies.push_back(e);
        this->count++;
    }

    std::shared_ptr<Enemy> create() const override {
        std::vector<std::shared_ptr<Enemy>> copies;
        for (const auto& e : enemies)
            copies.push_back(e->create());
        return std::make_shared<Pack>(copies);
    }

        std::string getdescription() const override {
            std::string g= "Pack of "+std::to_string(count)+" members (power "+ std::to_string(combatPower) +", loot "+ std::to_string(loot)+", "
                          "damage "+std::to_string(damge)+")";
            return  g;
        }

};