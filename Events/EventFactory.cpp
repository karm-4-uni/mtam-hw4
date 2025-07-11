
#include "EventFactory.h"

#include "../Encounter/Encounter.h"
#include "../Encounter/Enemy.h"
#include "../SpecialEvent/PotionsMerchant.h"
#include "SpecialEvent/SolarEclipse.h"

std::shared_ptr<Event> EventFactory::createevent( std::string name) {
    if(name=="Snail") {
        std::shared_ptr<Event> new_event = std::make_shared<Encounter>(std::make_shared<Snail>());
return new_event;
    }

    if(name=="Barlog") {
        std::shared_ptr<Event> new_event = std::make_shared<Encounter>(std::make_shared<Barlog>());
        return new_event;
    }
    if(name=="Slime") {
        std::shared_ptr<Event> new_event = std::make_shared<Encounter>(std::make_shared<Slime>());
        return new_event;
    }

if(name=="PotionsMerchant") {
    std::shared_ptr<Event> new_event = std::make_shared<PotionsMerchant>();
    return new_event;

}


    if(name=="SolarEclipse") {
std::shared_ptr<Event> new_event = std::make_shared<SolarEclipse>();
        return new_event;

    }


if(!(name.find("Pack"))) {

    throw std::invalid_argument("Undefined event type: " + name);

}
    else {
        int i=5;
        std::string f="";

        for ( ;i<name.length();i++) {
            while(name.at(i)!=' ') {
                f+=name.operator[](i);
                i++;
            }
        }
        i++;
            int enemynum= std::stoi(f);
            std::shared_ptr<Event> new_event = std::make_shared<Encounter>(std::make_shared<Pack>());
f = "";
            for(int j =0;i<enemynum;j++) {
          while (name.at(i)!=' ') {
              f+ name.operator[](i);

              i++;
          }


            }


        }
    }





