# include "Turn.h"
# include "../../Events/Event.h"

Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent)
    : currPlayer(currPlayer), currEvent(currEvent) {}


Turn::~Turn() {

}

void Turn::applyTurn() {
<<<<<<< HEAD
 //   currEvent.operator*().
this->currPlayer.operator*().doEvent(currEvent);
    // this->currEvent->applyEvent(*this->currPlayer);
=======
this->currPlayer->doEvent(currEvent);
>>>>>>> dd286c1 (fix get charactor root cuse)
}

const std::string Turn::printTurnoutcome() {
    //add getdetails
    //return   currEvent.get().getdetails();
    return "";
}