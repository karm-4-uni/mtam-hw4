

#include "SolarEclipse.h"
SolarEclipse::SolarEclipse():SpecialEvent("SolarEclipse")
{
}



string SolarEclipse::getDescription() const {
    return getname();

}
Player& SolarEclipse:: applyEvent(Player &currPlayer) {
//do
    return currPlayer;
}