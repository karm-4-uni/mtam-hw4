 #  pragma once
# include "Turn.h"


Turn::Turn() {

}
Turn::Turn(std::shared_ptr<Player> currPlayer, std::shared_ptr<Event> currEvent) {

}
void Turn::applyTurn(Player &player) {
 this->currEvent->applyEvent(player);
}
