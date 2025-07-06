
# include "Round.h"



Round::Round() {

}

Round::Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers,
    std::shared_ptr<std::queue<std::shared_ptr<Event>>>events) {
    this->players  =otherplayers;
    this->events =events;
    this->RoundNum = 1;
    for(int i=0;i<this->players->size();i++) {
        turns.push_back(std::make_shared<Turn>());
    }
}

void Round::startRound() {


    std::queue<std::shared_ptr<Player>> players_copy = *players;

    while (!players_copy.empty()) {
        std::shared_ptr<Player> p = players_copy.front();
        players_copy.pop();
        if (p) {
//p.playturn(Event)   make the player do the event  (inside this function we will use the applay turn(player) {double dispatch}
            std::shared_ptr<Event> front = this->events->front();
            events->pop();
            events->push(front);
        }
    }



}

