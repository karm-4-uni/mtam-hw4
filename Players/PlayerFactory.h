//
// Created by Admin on 03/07/2025.
//

#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#endif //PLAYERFACTORY_H

class  player_factory {
public:

    static std::unique_ptr<Player>
    createPlayer(const std::string& type,
        const std::string& name);

};