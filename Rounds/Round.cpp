
# include "Round.h"

#include <cassert>
#include <stdexcept>
#include "Turns/Turn.h"
#include "../Utilities.h"
int Round::turnNumber = 0;
Round::Round() {

}


Round::Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>> players,
             std::shared_ptr<std::queue<std::shared_ptr<Event>>> events)
  : players(std::move(players))
  , events(std::move(events))
{
    this->RoundNum = 1;

}
Round::~Round() {
    players.reset();
    events.reset();

}



void Round::startRound() {
     std::size_t count = 0 ;
    std::queue<std::shared_ptr<Player>> players_copy = *players;
    assert(!players_copy.empty() && !events->empty());
    std::size_t playersize = players_copy.size();
    //IF cant happen but if it happend then the code is fully worng
    try {
        for (size_t i = 1; i <= playersize; ++i) {
            std::shared_ptr<Turn>  newTurn;
            std::shared_ptr<Player> p = players_copy.front();
            players_copy.pop();
            if (p) {
                std::shared_ptr<Event> frontEvent = events->front();
                events->pop();
                // Each player applies the current event
                if (frontEvent) {
                    newTurn = std::make_shared<Turn>(p,frontEvent,turnNumber++);
                }
                //  frontEvent->applyTurn(*p);  // double dispatch
                // Push event to the back
                events->push(frontEvent);
                count++;
                newTurn.get()->applyTurn();
                printTurnDetails(turnNumber,*p,*frontEvent);
                printTurnOutcome(newTurn.get()->printTurnoutcome());
            }

        }   checkPlayers();
    } catch (...) {
        throw std::runtime_error("can't creat  an Event");
    }
turnNumber++;
}

void Round::checkPlayers() {
     std::queue<std::shared_ptr<Player>> q = *players;
        size_t n = q.size();
    for ( size_t i = 0; i < n; ++i){
        std::shared_ptr<Player> p = q.front();
        q.pop();
        if (!p->isDead()) {
            q.push(p);
        }
    }
}

