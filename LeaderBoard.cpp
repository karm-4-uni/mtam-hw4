


#include <algorithm>

#include "Leaderboard.h"
#include "Players/Player.h"
LeaderBoard::LeaderBoard(std::vector<std::shared_ptr<Player>> playersV)
: playersV(playersV){
orderPlayers();}

void LeaderBoard::orderPlayers() {
        int n = playersV.size();
        int aliveEnd = 0;
    try {
        for (int i = 0; i < n; ++i) {
            if (!playersV[i]->isDead()) {
                std::swap(playersV[i], playersV[aliveEnd]);
                ++aliveEnd;
            }
        }
        for (int i = 0; i < aliveEnd; ++i) {
            int best = i;
            for (int j = i + 1; j < aliveEnd; ++j) {
                if (*playersV[j] >= *playersV[best])
                    best = j;
            }
            if (best != i)
                std::swap(playersV[i], playersV[best]);
        }
    } catch (...) {
        throw std::runtime_error("orderplayer Error");
    }

    }




//
// void LeaderBoard::orderPlayers( ) {
// int size = this->playersV.size() ;
//     int i = 0  , j = 1 ;
//     int index = 0 ;
//     try {
//
//          if(size == 1 ){ return;}
//     while ( i < size   ) {
//         if(!playersV[i].get()->isDead()) {
//    while (j < size ) {
//             if(!playersV[j].get()->isDead()) {
//                   if(*playersV[i].get() <= *playersV[j ].get()) {
//                 std::shared_ptr<Player> temp = playersV[i];
//                 playersV[i] = playersV[j];
//                 playersV[j] = temp ;
//
//                 j++;
//             } i++;
//         }
//             }
//
//         }
//
//
//     }
//     } catch (...) {
//         throw std::runtime_error("Wow ! not expeting in order player");
//     }

//}