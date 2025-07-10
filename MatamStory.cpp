
#include "MatamStory.h"
# include <fstream>
# include <iostream>
# include <string>

#include "Encounter/Encounter.h"
#include "Utilities.h"

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {
    auto events = std::make_shared<std::queue<std::shared_ptr<Event>>>();
    std::string line,first="" ;
    int i=0;
    while(std::getline(eventsStream,line )) {
        if(line.operator[](i)!=' ') {
            first+= line.operator[](i);

        }else {
            if(first == "Snail") {
                events->push(std::make_shared<Event>());

            }
                if(first=="Barlog") {

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
