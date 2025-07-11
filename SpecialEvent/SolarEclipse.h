
#include "SpecialEvent.h"
class SolarEclipse: public SpecialEvent{

public:
    SolarEclipse():SpecialEvent("SolarEclipse"){}

    std:: string getDescription() const override;
    void applyEvent(std::shared_ptr<Charactor>charactor) override;
};




