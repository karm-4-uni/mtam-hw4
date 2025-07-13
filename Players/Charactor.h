
#pragma once
#include <memory>

#include "../Events/Enemy.h"

#include <string>
#include "Job.h"
#include "Behivior.h"
class Event;
class Job;
 class  Charactor  : public std::enable_shared_from_this<Charactor>{
  friend  class Warrior ;
  friend  class  Archer ;
  friend  class  Magician ;
  friend  class  job;
friend class Event;
  friend  class Behivior;
  class Enemy;
const std::string   name ;
  int Level;
     int CurrentHP;
     int maxHP;
     const std::shared_ptr< Job> job;
     const std::shared_ptr<Behivior> behivior ;
     int coin ;
     int force ;
 public:

  Charactor(std::string name,
         std::string jobName,
         std::string behaviorName,
         int hp,
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
  //const  std::shared_ptr<Job>& getJop() const;
  const std::shared_ptr<Job>& getJop() const;

  const bool isfullhp() const ;

  void doJob ();

//  void doEvent(std::shared_ptr<Event>event);

  bool operator>=( const Charactor& other) const;
bool operator== (const Charactor& other) const;


int getcombatpower();

 const std::shared_ptr<Job> getjob()  {
 return this->job;
}
  std::shared_ptr<Behivior>get_behivior() {
 return this->behivior;
}
  void doBehivior();

  void takeDamge(std::shared_ptr<Enemy>enemy);

 };
//tor<=(const Charactor& currntChar,const Charactor& other) ;