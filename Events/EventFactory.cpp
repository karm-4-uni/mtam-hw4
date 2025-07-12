
#include "EventFactory.h"
#include "Encounter.h"
#include "Enemy.h"
#include "PotionsMerchant.h"
#include "SolarEclipse.h"
#include <sstream>
#include <stdexcept>

std::shared_ptr<Event> EventFactory::createEvent(const std::string& name) {
    if (name == "Snail")
        return std::make_shared<Encounter>(std::make_shared<Snail>());
    if (name == "Slime")
        return std::make_shared<Encounter>(std::make_shared<Slime>());
    if (name == "Barlog")
        return std::make_shared<Encounter>(std::make_shared<Barlog>());
    if (name == "PotionsMerchant")
        return std::make_shared<PotionsMerchant>();
    if (name == "SolarEclipse")
        return std::make_shared<SolarEclipse>();

    if (name.substr(0, 4) == "Pack") {
        std::istringstream stream(name.substr(5));
        int count;
        stream >> count;
        if (!stream || count <= 0)
            throw std::invalid_argument("Invalid pack count");

        std::vector<std::shared_ptr<Enemy>> enemies;
        for (int j = 0; j < count; ++j) {
            std::string enemy_name;
            stream >> enemy_name;
            auto event = createEvent(enemy_name);
            auto encounter = std::dynamic_pointer_cast<Encounter>(event);
            if (!encounter) throw std::invalid_argument("Invalid enemy");
            enemies.push_back(encounter->getEnemy());
        }

        return std::make_shared<Encounter>(std::make_shared<Pack>(enemies));
    }

    throw std::invalid_argument("Unknown event: " + name);
}
