
#pragma once

#include <memory>
#include <string>
#include "Charactor.h"

class Enemy;
using std::string;
enum class Stat {
 Alive,
 Dead,
 empty
};

class Player {
 string name;
std::shared_ptr<Charactor> charactor ;
Stat status  ;

 static int numberofplayers ;
 const int playernumber;
 friend class PlayerFactory;
public:
Player(const string& name,const string& job,const string& behiviar
 , int health = 100
 , int coin = 10
 , int force = 0
 );
 Player(std::string name,
  std::shared_ptr<Charactor> charactor);
 ~Player() = default;
 Player(Player&&) = default;
 Player& operator=(Player&&) = default;
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


 const int getplayerID() const ;

 void doEvent(std::shared_ptr<Event> event);

  bool operator>( const Player& other) const;


 bool isDead() ;
// not done
 void Encounter(std::shared_ptr<Enemy> enemy);
 //
 void doBehivior();

 void takeDamge(std::shared_ptr<Enemy>enemy);
};
bool operator<(const Player& thisplayer ,const Player& other) ;

