
# include "Round.h"

#include <assert.h>
#include <stdexcept>


Round::Round() {

}

Round::Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers,
    std::shared_ptr<std::queue<std::shared_ptr<Event>>>events) {
    this->players  =otherplayers;
    this->events =events;
    this->RoundNum = 1;

}
Round::~Round() {
    players.reset();
    events.reset();

}



void Round::startRound() {
    int count = 0 ;
    std::queue<std::shared_ptr<Player>> players_copy = *players;
    assert(!players_copy.empty() && !events->empty());
    //IF cant happen but if it happend then the code is fully worng
    try {
          while ( count <  players_copy.size() ) {
              std::shared_ptr<Turn>  newTurn;
        std::shared_ptr<Player> p = players_copy.front();
        players_copy.pop();
        if (p) {
            std::shared_ptr<Event> frontEvent = events->front();
            events->pop();
            // Each player applies the current event
            if (frontEvent) {
 newTurn = std::make_shared<Turn>(p,frontEvent);
            }
              //  frontEvent->applyTurn(*p);  // double dispatch
            // Push event to the back
            events->push(frontEvent);
            count++;
           newTurn.get()->applyTurn();

        }

    }   checkPlayers();
    } catch (...) {
        throw std::runtime_error("can't creat  an Event");
    }

}

// void Round::startRound() {
//
//
//     std::queue<std::shared_ptr<Player>> players_copy = *players;
//
//     while (!players_copy.empty()) {
//         std::shared_ptr<Player> p = players_copy.front();
//         players_copy.pop();
//         if (p) {
// //p.playturn(Event)   make the player do the event  (inside this function we will use the applay turn(player) {double dispatch}
//             std::shared_ptr<Event> front = this->events->front();
//             events->pop();
//             events->push(front);
//         }
//     }


void Round::checkPlayers() {
    for (int i = 0  ; i <  players.get()->size() ; i++)
    {
        if(players.get()->front().get()->isDead()) {
            players.get()->pop();
        } else {
            players.get()->push(players.get()->front());
        }
    }
}




