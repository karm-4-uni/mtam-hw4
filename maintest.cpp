#include <iostream>
#include <vector>

#include "PlayerFactory.h"   // has createPlayer(...)


int main() {
    try {
        // --- Create players via the factory ---
        Player p1 = Playerfactory::createPlayer(
            "Aragorn",        // name  (≤15 chars)
            "Warrior",        // job
            "Responsible",    // behaviour
            40,               // force
            120,              // health
            30                // coins
        );

        Player p2 = Playerfactory::createPlayer(
            "Gandalf",        // name
            "Magician",       // job
            "Risktaking",     // behaviour
            50,               // force
            110,              // health
            50                // coins
        );

        Player p3 = Playerfactory::createPlayer(
            "Legolas",        // name
            "Archer",         // job
            "Responsible",    // behaviour
            35,               // force
            95,               // health
            25                // coins
        );

        // --- Put them into a party vector ---
        std::vector<Player*> party { &p1, &p2, &p3 };

        // --- Print descriptions ---
        std::cout << "=== Party Roster ===\n";
        for (const Player* pl : party) {
            std::cout <<  pl->getDescription() << std::endl ;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error creating player: " << ex.what() << '\n';
    }

    return 0;
}