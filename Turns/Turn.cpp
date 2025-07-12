// #  pragma once
# include "Turn.h"


Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent)
    : currPlayer(currPlayer), currEvent(currEvent) {}


Turn::~Turn() {

}

void Turn::applyTurn() {
this->currPlayer.get()->doEvent(*currEvent.get());
// this->currEvent->applyEvent(*this->currPlayer);
}

const std::string Turn::printTurnoutcome() {
    //add getdetails
  return   currEvent.get().getdetails();
}
