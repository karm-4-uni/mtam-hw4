
#pragma once

#include <iostream>

#include "Players/Player.h"
#include "Events/Event.h"
# include <memory>

#include "Events/Round.h"

enum class Gamestat {
 notOver,
 ALLPlayerDead,
 Winner
};
class MatamStory{
private:
 static int m_turnIndex;
 std::shared_ptr<std::queue<std::shared_ptr<Player>>>  playersQ ;
 std::vector<std::shared_ptr<Player>> playersV;
 //std::vector<std::unique_ptr<Round>> Rounds;
 std::shared_ptr<std::queue<std::shared_ptr<Event>>> events;

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
 const Gamestat isGameOver() ;


 void addPlayers( std::istream& in = std::cin);
 void addEvants(std::istream& in = std::cin);

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

 //moved to round
 //void checkdeadplayer() ;
void orderPlayers();

};
