
#include "MatamStory.h"

#include <algorithm>
# include <fstream>
# include <iostream>
# include <string>
#include "Events/Event.h"
#include "Players/Player.h"
#include "Events/Encounter.h"
#include "Utilities.h"
#include "Events/EventFactory.h"

#include "Players/PlayerFactory.h"

void printLeaderBordplayer(std::vector<std::shared_ptr<Player>> playersV) ;
MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
{
    playersQ = std::make_shared<std::queue<std::shared_ptr<Player>>>();
    events   = std::make_shared<std::queue<std::shared_ptr<Event>>>();

    /*==========================================*/
    try {
        addPlayers(playersStream);
    } catch (...) {
        std::cerr << "Invalid Players File " <<  "\n";
        throw;
    }
    // players added
    /*==========================================*/
    // string EvantsFile ;
    // getline(eventsStream,EvantsFile);
    // std::ifstream inEvantFile(EvantsFile);
    try {
        addEvants(eventsStream);
    } catch (...) {
        throw std::runtime_error("Invalid Events File");

    }

    /*==========================================*/

    }

//return winnerindex
int getWinner(const std::vector<std::shared_ptr<Player>> playersv) {
     size_t i = 0;
    for( ; i < playersv.size() ; i++) {
        if( playersv[i].get()->getLevel() == 10 ) {
            return  i ;
        }

    }
    return i;
}


void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/
    for (auto it = playersV.begin();  // 1) initialization
         it != playersV.end();        // 2) loop‐condition
         ++it)                        // 3) increment
    {
        printStartPlayerEntry(it->get()->getplayerID(),*it->get());
    }

    /*=========================================================================================*/
    printBarrier();
    Gamestat gamestate = isGameOver();
    while (gamestate == Gamestat::notOver) {
        playRound();
         gamestate = isGameOver();
    }

    printRoundEnd();
 printLeaderBoardMessage();
    printLeaderBordplayer(playersV);
    printBarrier();
    printGameOver();

    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
 if(gamestate == Gamestat::Winner){ printWinner(*playersV[getWinner(playersV)]);}

    if(gamestate == Gamestat::ALLPlayerDead){ printNoWinners();}
    /*========================================================================*/
}
void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */
}


void printLeaderBordplayer(std::vector<std::shared_ptr<Player>> playersV) {
    for (auto it = playersV.begin();it !=  playersV.end();  ++it) {
        printLeaderBoardEntry(it->get()->getplayerID(), *it->get());
    }
}
void MatamStory::playRound() {
    printRoundStart();
std::shared_ptr<Round> new_round =  std::make_shared<Round> (playersQ,events );
 /*===== TODO: Play a turn for each player =====*/
        new_round.get()->startRound();
     /*=============================================*/
   // checkdeadplayer();
if(isGameOver() != Gamestat::notOver) {
    return;
}


orderPlayers();
    printRoundEnd();
    printLeaderBoardMessage();


    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
printLeaderBordplayer(this->playersV);
    /*=======================================================================================*/
    printBarrier();
}

const Gamestat MatamStory::isGameOver()  {
    /*===== TODO: Implement the game over condition =====*/
    // 0 = game isnt over
    // -1 all player dead
    // 1 there is one winner
    // 1< more than one winners
    if(playersQ.get()->size() == 0) {    return  Gamestat::ALLPlayerDead ; ;}

    int count = 0 ;
    for (size_t i = 0  ; i <  playersQ.get()->size() ; i++)
    {
        std::shared_ptr<Player> p = playersQ.get()->front();
        if(p->getLevel() == 10 ) {
            count++;
        }
       playersQ.get()->pop();

           playersQ.get()->push(p);
    }
    if(count == 1) { return Gamestat::Winner;}
    if(count == 0) {return  Gamestat::notOver;}
    /*===================================================*/
    return  Gamestat::notOver;
}




// void MatamStory::addPlayers(std::istream &in) {
//     std::string line;
//     int  numberofplayrs = 0;
//     std::vector<string> playerinput  ;
//     while ( std::getline(in, line)) {
//      numberofplayrs++;
//         if(numberofplayrs > 6) {
//             throw std::domain_error("There only be 6 player's");
//         }
//         playerinput.clear();
//
//         std::string::size_type i = 0 ;
//
// while (i < line.size() && line[i] != ' ') {
//      string word = "";
//         while (i < line.size() && line[i] == ' '){i++;}
//         while (line[i] != ' ' && i < line.size()) {
//             word += line[i++];
//         }
//
//         playerinput.push_back(word);
//         word.clear();
// }
//         if(playerinput.size() != 3 ) {
//             throw std::domain_error("Invalid input");
//         }
// std::shared_ptr<Player> player1 = PlayerFactory::createPlayer(
//           playerinput[0],
//           playerinput[1],
//           playerinput[2]
//           ,numberofplayrs);
//        playersQ.get()->push(player1);
//         playersV.push_back(player1);
//     }
// }


void MatamStory::addEvants(std::istream &in) {
    std::string line;
   // std::vector<string> Evantinput  ;
    EventFactory factory;

    while (!events->empty()) events->pop();
    while ( std::getline(in, line)) {
        if (line.empty()) { continue;}
        try {
          std::shared_ptr<Event> newEvent = factory.createEvent(line);
        events->push(newEvent);
        } catch (...) {
            throw std::runtime_error("Invalid Events File");
        }


    }
}


//moved to round
// void MatamStory::checkdeadplayer() {
//     for (size_t i = 0  ; i <  playersQ.get()->size() ; i++)
//     {
//       if(playersQ.get()->front().get()->isDead()) {
//          playersQ.get()->pop();
//       } else {
//           playersQ.get()->push(playersQ.get()->front());
//       }
//     }
// }
void MatamStory::orderPlayers() {
      this->playersV;
    size_t n = this->playersV.size();
    for (size_t i = 0; i < n; ++i) {
        size_t bestplayer = i;
        for (size_t j = i + 1; j < n; ++j) {
            // inline strict compare: level ↓, coins ↓, name ↑
            auto &A = *playersV[j], &B = *playersV[bestplayer];
            if (   (A.getLevel()  > B.getLevel())
                || (A.getLevel() == B.getLevel() && A.getCoins()  > B.getCoins())
                || (A.getLevel() == B.getLevel() && A.getCoins() == B.getCoins()
                    && A.getName()   <  B.getName()) )
            {
                bestplayer = j;
            }
        } std::swap(playersV[i], playersV[bestplayer]);}
}


void MatamStory::addPlayers(std::istream& in) {
    std::string line;
    int count = 0;

    while (std::getline(in, line)) {
        // Skip blank/whitespace-only
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;

        ++count;
        if (count > 6)
            throw std::domain_error("There can only be up to 6 players");

        std::vector<std::string> words;
        std::size_t i = 0;
        while (i < line.size()) {
            // skip spaces
            while (i < line.size() && std::isspace(line[i])) ++i;
            if (i >= line.size()) break;
            std::string w;
            while (i < line.size() && !std::isspace(line[i]))
                w += line[i++];
           words.push_back(w);
        }

        if (words.size() != 3)
            throw std::domain_error("Invalid Players File");

        auto player = PlayerFactory::createPlayer(
            words[0], words[1], words[2], count);
        playersQ->push(player);
        playersV.push_back(player);
    }

    if (count == 0)
        throw std::domain_error("No players provided");
}