
#include "MatamStory.h"
# include <fstream>
# include <iostream>
# include <string>
#include "Events/Event.h"
#include "Players/Player.h"
#include "Events/Encounter.h"
#include "Utilities.h"

#include "Players/PlayerFactory.h"
static int numberofplayrs = 0  ;
MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    auto events = std::make_shared<std::queue<std::shared_ptr<Event>>>();
    std::string line,first="" ;
    int i=0;
    while(std::getline(eventsStream,line )) {
        if(line.operator[](i)!=' ') {
            first+= line.operator[](i);

        }else {
            if(first == "Snail") {
                events->push(std::make_shared<Encounter>());

            }
                if(first=="Barlog") {

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
                }
                    if(first=="Pack") {

                    }
                        if(first=="Slime") {

                        }
            if(first=="SolarEclipse") {

            }
            if( first=="PotionsMerchant") {

            }
        }
    }





    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
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
        playersQ.push(player1);
        playersV.push_back(player1);
    }
}

