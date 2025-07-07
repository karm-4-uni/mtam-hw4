
#pragma once

#include <memory>
#include <string>
#include "Charactor.h"

using std::string;
enum class Stat {
 Alive,
 Dead,
 empty
};

class Player {
 string name;
std::unique_ptr<Charactor> charactor ;
Stat status  ;
 static  int playernumber  ;
public:
Player(string name, string job,string behiviar
 , int health = 100
 , int coin = 10
 , int force = 0
 );
 Player(std::string name,
  std::unique_ptr<Charactor> charactor,
  Stat status);
    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;


 // return charactor refrence
 const Charactor& getCharator() const;
 Charactor& getCharator() ;

 const bool isfullhp() const ;

};
