
#pragma once

#include <iostream>

#include "Players/Player.h"
#include "Events/Event.h"
# include <memory>

#include "Rounds/Round.h"

class MatamStory{
private:
 static int numberofplayrs  ;
    unsigned int m_turnIndex;
//std::vector<std::unique_ptr<Round>> Rounds;
std::queue<Player> players ;
    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;


 void addPlayers( std::istream& in = std::cin);

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();

};
