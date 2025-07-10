//
// Created by Admin on 03/07/2025.
//

#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#endif //PLAYERFACTORY_H

#include <memory>
#include <string>
#include "Player.h"
class  PlayerFactory {
public:
    static std::shared_ptr<Player> createPlayer(
       const std::string& name,
       const string& job,
       const string& behavior,
       int coin = 10,
       int health = 100 ,
       int force = 5
   );
};