//
// Created by Admin on 03/07/2025.
//

#ifndef CHARACTOR_H
#define CHARACTOR_H
#include <memory>

#endif //CHARACTOR_H
#include <string>
#include "Jobs/Job.h"
#include "Behiviors/Behivior.h"
 class  Charactor {
  friend  class Jop;
  friend  class Behivior;

const std::string   name ;
  int Level;
     int CurrentHP;
     int maxHP;
     const std::unique_ptr<Job> job;
     const std::unique_ptr<Behivior> behivior ;
     int coin ;
     int force ;
 public:

  Charactor(std::string name,
            const std::string job,
           const std::string behavior,
           int hp ,
            int coin,
            int force);
     /**
   * Gets the description of the player
   *
   * @return - description of the player
  */
  ~Charactor()  = default;
std::string getDescription() const;

     /**
      * Gets the name of the player
      *
      * @return - name of the player
     */
std::string getName() const;

     /**
      * Gets the current level of the player
      *
      * @return - level of the player
     */
     int getLevel() const;
  void setLevel(int newLevel);

     /**
      * Gets the of force the player has
      *
      * @return - force points of the player
     */
     int getForce() const;
  void setForce(int newForce);

     /**
      * Gets the amount of health points the player currently has
      *
      * @return - health points of the player
     */
     int getHealthPoints() const;
  //health represnt the amount of increse or dectrece
  void setHealthPoints(int gainedhealth);

     /**
      * Gets the amount of coins the player has
      *
      * @return - coins of the player
     */
     int getCoins() const;
void setCoins(int gainedCoin);

  const int getMaxHP() const ;
  const  Job& getJop() const;

  const bool isfullhp() const ;

  void doJob ();


 };
