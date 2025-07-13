# include "Turn.h"
# include "../../Events/Event.h"
#include "../../Utilities.h"
Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent
    ,int turnnumber)
    : currPlayer(currPlayer), currEvent(currEvent) , turnnumber(turnnumber) {}


Turn::~Turn() {

}

void Turn::applyTurn() {
    printTurnDetails(turnnumber,*currPlayer,*currEvent);
this->currPlayer->doEvent(currEvent);

}
//
// const std::string Turn::printTurnoutcome() {
//     //add getdetails
//     //return   currEvent.get().getdetails();
//     return "";
// }