
# include "Round.h"

#include <cassert>
#include <iostream>
#include <stdexcept>
#include "Turns/Turn.h"
#include "../Utilities.h"
int Round::turnNumber = 0;
Round::Round() {

}

Round::Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>> players,
             std::shared_ptr<std::queue<std::shared_ptr<Event>>>  events)
    : players(std::move(players)),
      events (std::move(events))

{}
Round::~Round() {
    players.reset();
    events.reset();

}



void Round::startRound() {
     std::size_t count = 0 ;
    //std::queue<std::shared_ptr<Player>> players_copy = *players;
    assert(!players.get()->empty() && !events->empty());
    std::size_t playersize = players.get()->size();
    //IF cant happen but if it happend then the code is fully worng
    try {
        for (std::size_t i = 0; i < playersize; ++i) {
            // 1) rotate player
            auto p = players->front();
            players->pop();
            players->push(p);

            // 2) rotate event
            auto e = events->front();
            events->pop();
            events->push(e);

            // 3) advance turnNumber exactly once
            ++turnNumber;
            auto currentTurn = turnNumber;

            // 4) construct, apply, and print
            auto newTurn = std::make_shared<Turn>(p, e, currentTurn);
            newTurn->applyTurn();
        //    printTurnDetails(currentTurn, *p, *e);
          //  printTurnOutcome(newTurn.get()->printTurnoutcome());
            std::cout << "\n";
            }
checkPlayers();

    } catch (...) {
        throw std::runtime_error("can't creat  an Event");
    }
  //  std::cout << "\n";
}

void Round::checkPlayers() {
        size_t n = players->size();
    for ( size_t i = 0; i < n; ++i){
        std::shared_ptr<Player> p = players->front();
       players->pop();
        if (!p->isDead()) {
            players->push(p);
        }
    }
}

