
#include "MatamStory.h"
# include <fstream>
# include <iostream>
# include <string>

#include "Events/Encounter.h"
#include "Utilities.h"

#include "Players/PlayerFactory.h"
static int numberofplayrs = 0  ;
MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

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
        while (i < line.size() && line.operator[](i) == ' '){i++;}
        while (line.operator[](i) != ' ' && i < line.size()) {
            word += line.operator[](i);
        }

        playerinput.push_back(word);
        word.clear();
}
        if(playerinput.size() != 3 ) {
            throw std::domain_error("Invalid input");
        }
std::shared_ptr<Player> player1 = PlayerFactory::createPlayer(
          playerinput.operator[](0),
          playerinput.operator[](1),
          playerinput.operator[](2));
        playersQ.push(player1);
        playersV.push_back(player1);
    }
}

