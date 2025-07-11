

#include "../Events/Event.h"

#include "Enemy.h"

class Charactor;

class Encounter :  public Event {
public:
    Encounter();
    std::shared_ptr<Enemy> enemy;
Encounter(std::shared_ptr<Enemy> enemy);
    std::shared_ptr<Enemy> Encounter::getEnemy() const {
        return enemy;
    }
std::string getDescription() const override;
     void applyEvent(std::shared_ptr<Charactor>charactor) override ;
};


