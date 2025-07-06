//
// Created by Admin on 05/07/2025.
//
#include "PlayerFactory.h"

#include <stdexcept>

#include "Behiviors/Responsible.h"
#include "Behiviors/RiskTaking.h"
#include "Jobs/Archer.h"
#include "Jobs/Magician .h"
#include "Jobs/Warrior.h"


Player Playerfactory::createPlayer(const std::string &name
                                   ,string job
                                   ,string behavior
                                   ,int force
                                   ,int health
                                   ,int coin) {
         if (name.length() > 15)
             throw std::invalid_argument("Name must be 15 characters or fewer.");
         if (force <= 0)
             throw std::invalid_argument("Force must be positive.");
         if (health <= 0)
             throw std::invalid_argument("Health must be positive.");
         if (coin < 0)
             throw std::invalid_argument("Coin cannot be negative.");


         std::unique_ptr<Job> jobPtr;
         if (job == "Warrior") jobPtr = std::make_unique<Warrior>();
         else if (job == "Magician") jobPtr = std::make_unique<Magician>();
         else if (job == "Archer") jobPtr = std::make_unique<Archer>();
         else throw std::invalid_argument("Unknown job: " + job);

         // === Behavior selection ===
         std::unique_ptr<Behivior> behPtr;
         if (behavior == "Responsible") behPtr = std::make_unique<Responsible>();
         else if (behavior == "Risktaking") behPtr = std::make_unique<Risktaking>();
         else throw std::invalid_argument("Unknown behavior: " + behavior);

         return Player(
             name,
             health,
             coin,
             force,
             job,
             behavior
         );
    }
