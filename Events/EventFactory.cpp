
#include "EventFactory.h"

#include <memory>
#include <stdexcept>
#include <sstream>
#include "../Encounter/Encounter.h"
# include "../Encounter/Enemy.h"
# include "../SpecialEvent/PotionsMerchant.h"
# include "../SpecialEvent/SolarEclipse.h"
std::shared_ptr<Event> EventFactory::createEvent(const std::string &name) {
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
        std::istringstream stream(name.substr(5)); // skip "Pack "
        int count;
        stream >> count;

        if (!stream || count <= 0)
            throw std::invalid_argument("Invalid pack count in event name: " + name);

        std::vector<std::shared_ptr<Enemy>> enemies;
        for (int j = 0; j < count; ++j) {
            std::string enemy_name;
            stream >> enemy_name;

            if (enemy_name.empty())
                throw std::invalid_argument("Missing enemy name at position " + std::to_string(j));

            auto event = createEvent(enemy_name);
            auto encounter_ptr = std::dynamic_pointer_cast<Encounter>(event);
            if (!encounter_ptr)
                throw std::invalid_argument("Non-enemy used inside pack: " + enemy_name);

            auto enemy_ptr = encounter_ptr->getEnemy();
            if (!enemy_ptr)
                throw std::invalid_argument("Null enemy inside pack: " + enemy_name);

            enemies.push_back(enemy_ptr);
        }

        return std::make_shared<Encounter>(std::make_shared<Pack>(enemies));
    }

    throw std::invalid_argument("Unknown event type: " + name);
}


