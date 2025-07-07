#pragma once
#include "Player.h"

# include "memory"
class Enemy {
protected:
    int loot=0;
    int combatPower=0;
    int damge=0;

public:
    Enemy();
    ~Enemy() = default;
   virtual std::shared_ptr<Enemy> create() const=0;

    virtual void attack(std::shared_ptr<Player>)const =0;


};

class Snail : public Enemy {

    Snail() {
        this->damge=10;
        this->loot =2;
        this->combatPower=5;
    }
    std::shared_ptr<Enemy> create() const override {
    return std::make_shared<Snail>();
    }
     void  attack(std::shared_ptr<Player>)const  override {
//player.takedamge
    }
};

class Slime : public Enemy {

    Slime() {
        this->damge=25;
        this->loot =5;
        this->combatPower=12;
    }
    std::shared_ptr<Enemy> create() const override
    {
    return std::make_shared<Slime>();    }
    void attack(std::shared_ptr<Player>) const  override {
//player.take damge
    }
};

class Barlog : public Enemy {

    Barlog() {
        this->damge=10;
        this->loot =2;
        this->combatPower=5;
    }
    std::shared_ptr<Enemy> create()  const override {
    return std::make_shared<Barlog>();
    };
void attack(std::shared_ptr<Player>) const  override {
//player.takedamge
}
    class Pack : public Enemy {
    std::vector<std::shared_ptr<Enemy>> enemies;
public:
    Pack(const std::vector<std::shared_ptr<Enemy>>& es) : enemies(es) {}

    void attack(std::shared_ptr<Player> player) const override {
        for (const auto& e : enemies)
            e->attack(player);
    }

    std::shared_ptr<Enemy> create() const override {
        std::vector<std::shared_ptr<Enemy>> copies;
        for (const auto& e : enemies)
            copies.push_back(e->create());
        return std::make_shared<Pack>(copies);
    }
};

};