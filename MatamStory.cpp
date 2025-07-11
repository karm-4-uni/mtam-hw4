
#include "MatamStory.h"
# include <fstream>
# include <iostream>
# include <string>

#include "Encounter/Encounter.h"
#include "Utilities.h"
#include "Events/EventFactory.h"

#include "Players/PlayerFactory.h"



static int numberofplayrs = 0  ;
MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    /*==========================================*/
    try {
        string Playersfile ;
    getline(std::cin,Playersfile);
    std::ifstream inPlayersfile(Playersfile);
    if (!inPlayersfile) {
        throw  std::runtime_error("can't open  Playerfile ");
    }
addPlayers(inPlayersfile);
    } catch (...) {
        std::cerr << "Error adding players: " <<  "\n";
        throw;
    }
    // players added
    /*==========================================*/
    string EvantsFile ;
    getline(std::cin,EvantsFile);
    std::ifstream inEvantFile(EvantsFile);

    /*==========================================*/
           play();
    }

//return winnerindex
int getWinner(const std::vector<std::shared_ptr<Player>> playersv) {
    for(int i = 0 ; i < playersv.size() ; i++) {
        if( playersv[i].get()->getLevel() == 10 ) {
            return  i ;
        }

    }
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
        Gamestat gamestate = isGameOver();
    }
    printGameOver();
    if(gamestate == Gamestat::ALLPlayerDead){ printNoWinners();}
    if(gamestate == Gamestat::Winner){ printWinner(*playersV[getWinner(playersV)]);}

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

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

void MatamStory::playRound() {

    printRoundStart();

std::shared_ptr<Round> new_round =  std::make_shared<Round> (playersQ,events );
    new_round.get()->startRound();
    checkdeadplayer();
if(isGameOver() != Gamestat::notOver) {
    return;
}
    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

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
    for (int i = 0  ; i <  playersQ.get()->size() ; i++)
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
}




void MatamStory::addPlayers(std::istream &in) {
    std::string line;
    int  playercount = 0 ;
    std::vector<string> playerinput  ;
    while ( std::getline(in, line)) {
        playercount++;
        if(playercount > 6) {
            throw std::domain_error("There only be 6 player's");
        }
        playerinput.clear();

        int i = 0 ;

while ( i < line.size()) {
     string word = "";
        while (i < line.size() && line[i] == ' '){i++;}
        while (line[i] != ' ' && i < line.size()) {
            word += line[i++];
        }

        playerinput.push_back(word);
        word.clear();
}
        if(playerinput.size() != 3 ) {
            throw std::domain_error("Invalid input");
        }
std::shared_ptr<Player> player1 = PlayerFactory::createPlayer(
          playerinput[0],
          playerinput[1],
          playerinput[2]);
       playersQ.get()->push(player1);
        playersV.push_back(player1);
    }
}


void MatamStory::addEvants(std::istream &in) {
    std::string line;
   // std::vector<string> Evantinput  ;

    while ( std::getline(in, line)) {
        if (line.empty()) { continue;}
        while (!events->empty()) events->pop();
        try {
          std::shared_ptr<Event> newEvent = EventFactory::createEvent(line);
        events->push(newEvent);
        } catch (...) {
            throw std::runtime_error("EventFactory cant creat event");
        }


    }
}

void MatamStory::checkdeadplayer() {
    for (int i = 0  ; i <  playersQ.get()->size() ; i++)
    {
      if(playersQ.get()->front().get()->isDead()) {
         playersQ.get()->pop();
      } else {
          playersQ.get()->push(playersQ.get()->front());
      }
    }
}


