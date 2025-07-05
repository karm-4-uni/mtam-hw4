
# include "Round.h"



Round::Round() {
    
}

Round::Round(std::shared_ptr<std::queue<std::shared_ptr<Player>>>otherplayers) {
    players =otherplayers;
    this->RoundNum=1;
    for(int i=0;i<this->players->size();i++) {
        turns.push_back(std::make_shared<Turn>());
    }

}