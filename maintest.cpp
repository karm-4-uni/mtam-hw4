//
// Created by Admin on 05/07/2025.
//
#include <iostream>
#include "Player.h"
#include "PlayerFactory.h"
#include "Behiviors/Responsible.h"
#include "Jobs/Magician .h"

int main() {
    try {
        std::cout << "=== Testing PlayerFactory ===" << std::endl;

        Player p1 = Playerfactory::createPlayer(
            "Alice",
            std::make_unique<Magician>(),
            std::make_unique<Behivior>(std::make_unique<Responsible>()),
            5,   // force
            100, // health
            10   // coin
        );

        std::cout << "Player 1 created by factory:\n";
        std::cout << "Name: " << p1.getName() << std::endl;
        std::cout << "Description: " << p1.getDescription() << std::endl;
        std::cout << "HP: " << p1.getHealthPoints() << "/" << p1.getCharator().getMaxHP() << std::endl;
        std::cout << "Coins: " << p1.getCoins() << std::endl;
        std::cout << "Force: " << p1.getForce() << std::endl;
        std::cout << "Level: " << p1.getLevel() << std::endl;

        std::cout << "\n=== Testing direct Player constructor ===" << std::endl;

        Player p2("Bob", 100, 10, 5, "Warrior", "Selfish");

        std::cout << "Player 2 created with strings:\n";
        std::cout << "Name: " << p2.getName() << std::endl;
        std::cout << "Description: " << p2.getDescription() << std::endl;
        std::cout << "HP: " << p2.getHealthPoints() << "/" << p2.getCharator().getMaxHP() << std::endl;
        std::cout << "Coins: " << p2.getCoins() << std::endl;
        std::cout << "Force: " << p2.getForce() << std::endl;
        std::cout << "Level: " << p2.getLevel() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "\n❌ Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
