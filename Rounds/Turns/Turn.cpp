# include "Turn.h"
# include "../../Events/Event.h"
#include "../../Utilities.h"
Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent)
    : currPlayer(currPlayer), currEvent(currEvent) {}


Turn::~Turn() {

}

void Turn::applyTurn() {
    printTurnDetails(1,*currPlayer,*currEvent);
this->currPlayer->doEvent(currEvent);
}

const std::string Turn::printTurnoutcome() {
    //add getdetails
    //return   currEvent.get().getdetails();
    return "";
}