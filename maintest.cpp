
//
// #include <iostream>
// #include <string>
// #include <vector>
// #include <sstream>
// #include <exception>
// #include "MatamStory.h"
//
// int main() {
//     using namespace std;
//
//     // 1) Read events
//     cout << "Enter events (type END on its own line to finish):" << endl;
//     vector<string> eventLines;
//     string line;
//     while (getline(cin, line)) {
//         if (line == "END") break;
//         // skip blank lines if you like:
//         if (!line.empty())
//             eventLines.push_back(line);
//     }
//
//     // 2) Read players
//     cout << "\nEnter players (type END on its own line to finish):" << endl;
//     vector<string> playerLines;
//     while (getline(cin, line)) {
//         if (line == "END") break;
//         if (!line.empty())
//             playerLines.push_back(line);
//     }
//
//     // 3) Build input‐streams
//     ostringstream evStreamBuf, plStreamBuf;
//     for (auto &l : eventLines)  evStreamBuf << l << '\n';
//     for (auto &l : playerLines) plStreamBuf << l << '\n';
//
//     istringstream evStream(evStreamBuf.str()), plStream(plStreamBuf.str());
//
//     // 4) Run the game
//     try {
//         MatamStory game(evStream, plStream);
//
//         game.play();
//         // if your ctor already calls play(), you’re done
//     }
//     catch (const exception &e) {
//         cerr << "Error: " << e.what() << endl;
//         return 1;
//     }
//
//     return 0;
// }
// // int main() {
// //     try {
// //
// //         std::shared_ptr<Player> p1 = PlayerFactory::createPlayer(
// //             "Aragorn",        // name  (≤15 chars)
// //             "Warrior",        // job
// //             "Responsible",    // behaviour
// //             40,               // force
// //             120,              // health
// //             30                // coins
// //         );
// //
// //         std::shared_ptr<Player> p2 = PlayerFactory::createPlayer(
// //             "Gandalf",        // name
// //             "Magician",       // job
// //             "Risktaking",     // behaviour
// //             50,               // force
// //             110,              // health
// //             50                // coins
// //         );
// //
// //         std::shared_ptr<Player>  p3 = PlayerFactory::createPlayer(
// //             "Legolas",        // name
// //             "Archer",         // job
// //             "Responsible",    // behaviour
// //             35,               // force
// //             95,               // health
// //             25                // coins
// //         );
// //
// //         // --- Put them into a party vector --
// //         std::vector<std::shared_ptr<Player> > party { p1, p2, p3 };
// //
// //         // --- Print descriptions ---
// //         std::cout << "=== Party Roster ===\n";
// //         for (const std::shared_ptr<Player>  pl : party) {
// //             std::cout <<  pl.get()->getDescription() << std::endl ;
// //         }
// //         for (const std::shared_ptr<Player> pl : party) {
// //             std::cout <<  pl.get()->getplayerID() << std::endl ;
// //
// //         }
// //     }
// //     catch (const std::exception& ex) {
// //         std::cerr << "Error creating player: " << ex.what() << '\n';
// //     }
// //
// //     return 0;
// // }
// //
//
//
