#include "Turn.h"

#include <iostream>

#include "Event.h"
#include "../Utilities.h"
Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player>  currPlayer,
           std::shared_ptr<Event>   currEvent,
           int  turnnumber) : turnnumber(turnnumber)
  , currPlayer(std::move(currPlayer))
  , currEvent(std::move(currEvent))
{}
Turn::~Turn() {

}

void Turn::applyTurn() {
    printTurnDetails(turnnumber,*currPlayer,*currEvent);
this->currPlayer->doEvent(currEvent);
std::cout << "\n";
}
//
// const std::string Turn::printTurnoutcome() {
//     //add getdetails
//     //return   currEvent.get().getdetails();
//     return "";
// }