
#include "EventFactory.h"

#include "../Encounter/Encounter.h"
#include "../Encounter/Enemy.h"
#include "../SpecialEvent/PotionsMerchant.h"
#include "SpecialEvent/SolarEclipse.h"

std::shared_ptr<Event> EventFactory::createevent( std::string name) {
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
        int i = 5; 
        std::string f;

        while (i < name.length() && name.operator[](i) != ' ') {
            f += name.operator[](i++);
        }

        int count = std::stoi(f);
        ++i;
        std::vector<std::shared_ptr<Enemy>> enemies;

        for (int j = 0; j < count; ++j) {
            std::string enemy_type;

            while (i < name.length() && name.operator[](i) != ' ') {
                enemy_type += name.operator[](i++);
            }
            ++i;

            auto event = createevent(enemy_type);
            auto encounter_ptr = std::dynamic_pointer_cast<Encounter>(event);
            if (!encounter_ptr)
                throw std::invalid_argument("Non-enemy used inside pack: " + enemy_type);

            auto enemy = encounter_ptr->getEnemy();
            if (!enemy)
                throw std::invalid_argument("Null enemy inside pack: " + enemy_type);

            enemies.push_back(enemy);
        }

        return std::make_shared<Encounter>(std::make_shared<Pack>(enemies));
    }

    throw std::invalid_argument("Unknown event type: " + name);
}




