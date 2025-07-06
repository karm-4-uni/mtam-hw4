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


Player Playerfactory::createPlayer(const std::string& name,
 const std::string& job,
const std::string& behavior,
int  force,int  health, int  coin) {
 return Player(name,health, coin,  force,job,behavior);
}


