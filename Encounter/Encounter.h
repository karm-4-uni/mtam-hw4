

#include "../Events/Event.h"

#include "Enemy.h"

class Encounter :  public Event {

    std::shared_ptr<Enemy> enemy;
public:
    Encounter();
Encounter(std::shared_ptr<Enemy> enemy);

 string getDescription() const override;
    Player& applyEvent(Player &currPlayer) override ;

    std::shared_ptr<Enemy> getEnemy() const {
        return this->enemy;
    }
};


