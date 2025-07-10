
#include "SpecialEvent.h"
class SolarEclipse: public SpecialEvent{

public:
    SolarEclipse():SpecialEvent("SolarEclipse"){}

    std:: string getDescription() const override;
    Player& applyEvent(Player& currPlayer) override;
};




