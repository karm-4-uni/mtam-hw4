


#include <algorithm>

#include "Leaderboard.h"
#include  "../Players/Player.h"
LeaderBoard::LeaderBoard(std::vector<std::shared_ptr<Player>> playersV)
: playersV(playersV){
orderPlayers();}


void LeaderBoard::orderPlayers() {

    std::sort(
        playersV.begin(),
        playersV.end(),
        [](const std::shared_ptr<Player>& playerV1,
           const std::shared_ptr<Player>&  playerV2) {
            return *playerV1 > *playerV2;
        }
    );
}


void LeaderBoard::getLeaderBoard(std::ostream &out) {
    for (auto it = playersV.begin(); it != playersV.end(); ++it) {
        std::shared_ptr<Player> p = *it;
        // customize this to whatever you want to print:
        out << it->get()->getDescription() << std::endl ;
    }
}

// void LeaderBoard::orderPlayers( ) {
// int size = this->playersV.size() ;
//     int i = 0  , j = 1 ;
//     int index = 0 ;
//     if(size == 1 ){ return;}
//     while ( i < size  - 1 ) {
//         while (j < size ) {
//             if(*playersV[i].get() <= *playersV[j ].get()) {
//                 std::shared_ptr<Player> temp = playersV[i];
//                 playersV[i] = playersV[j];
//                 playersV[j] = temp ;
//                 j++;
//             } i++;
//         }
//     }
// }