//
// Created by Admin on 05/07/2025.
//
#include "PlayerFactory.h"

#include <stdexcept>

#include "Responsible.h"
#include "RiskTaking.h"
#include "Archer.h"
#include "Magician .h"
#include "Warrior.h"


std::shared_ptr<Player> PlayerFactory::createPlayer(const std::string& name,
 const std::string& job,
const std::string& behavior,
int IDnumber,
int  health,int  coin, int  force) {
std::shared_ptr<Player>  newplayer  = std::make_shared<Player>(
         name, job, behavior,IDnumber,
         health, coin, force
     );
 newplayer.get()->getCharator().doJob();
 return newplayer;
}



//