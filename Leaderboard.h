

#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

class Player;

class LeaderBoard {
std::vector<std::shared_ptr<Player>> playersV ;
LeaderBoard(std::vector<std::shared_ptr<Player>> playersV) ;

    void getLeaderBoard(std::ostream& out  = std::cout);
    void orderPlayers() ;
};
