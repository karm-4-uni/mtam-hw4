 #  pragma once
# include "Turn.h"


Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent)
    : currPlayer(currPlayer), currEvent(currEvent) {}


Turn::~Turn() {

}

void Turn::applyTurn() {

 this->currEvent->applyEvent(*this->currPlayer);
}
