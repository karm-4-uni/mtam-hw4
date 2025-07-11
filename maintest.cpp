#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "MatamStory.h"
#include "Players/PlayerFactory.h"
void runTest(const char* name) ;
int main() {
    try {

        std::shared_ptr<Player> p1 = PlayerFactory::createPlayer(
            "Aragorn",        // name  (≤15 chars)
            "Warrior",        // job
            "Responsible",    // behaviour
            40,               // force
            120,              // health
            30                // coins
        );

        std::shared_ptr<Player> p2 = PlayerFactory::createPlayer(
            "Gandalf",        // name
            "Magician",       // job
            "Risktaking",     // behaviour
            50,               // force
            110,              // health
            50                // coins
        );

        std::shared_ptr<Player>  p3 = PlayerFactory::createPlayer(
            "Legolas",        // name
            "Archer",         // job
            "Responsible",    // behaviour
            35,               // force
            95,               // health
            25                // coins
        );

        // --- Put them into a party vector --
        std::vector<std::shared_ptr<Player> > party { p1, p2, p3 };

        // --- Print descriptions ---
        std::cout << "=== Party Roster ===\n";
        for (const std::shared_ptr<Player>  pl : party) {
            std::cout <<  pl.get()->getDescription() << std::endl ;
        }
        for (const std::shared_ptr<Player> pl : party) {
            std::cout <<  pl.get()->getplayerID() << std::endl ;

        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error creating player: " << ex.what() << '\n';
    }
    std::istringstream emptyEvents{""};

    // 2) Construct MatamStory using the empty stream for events.
    //    We don't care about playersStream here because we'll
    //    call addPlayers by hand.
    MatamStory story(emptyEvents, emptyEvents);

    // 3) Now read your players *once* from cin:

    return 0;
}

void runTest(const char* name) {
    std::cout << "=== " << name << " ===\n";

    // 1) open the two inputs
    std::ifstream evs(std::string("tests/") + name + ".events");
    std::ifstream pls(std::string("tests/") + name + ".players");
    if (!evs || !pls) {
        std::cerr << "  ERROR: missing files for " << name << "\n\n";
        return;
    }

    // 2) run your story and capture its output to cout
    try {
        MatamStory story(evs, pls);
        story.play();
    }
    catch (const std::exception& e) {
        std::cerr << "  EXCEPTION: " << e.what() << "\n\n";
        return;
    }

    // 3) print the “expected” so you can compare by eye
    std::ifstream expf(std::string("tests/") + name + ".expected");
    std::string line;
    std::cout << "\n--- expected (" << name << ") ---\n";
    while (std::getline(expf, line)) {
        std::cout << line << "\n";
    }
    std::cout << "\n\n";
}

