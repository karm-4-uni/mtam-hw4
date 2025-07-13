cmake_minimum_required(VERSION 3.29)
project(mtam_hw4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List *only* your .cpp files here—headers are found by your include paths.
add_executable(mtam_hw4
        main.cpp

        # utilities
        Utilities.cpp

        # players
        Players/Player.cpp
        Players/Charactor.cpp
        Players/PlayerFactory.cpp
        Players/Jobs/Job.cpp

        # events
        Events/Event.cpp
        Events/EventFactory.cpp
        Events/Encounter.cpp
        Events/SpecialEvent.cpp
        Events/PotionsMerchant.cpp
        Events/SolarEclipse.cpp

        # rounds & turns  ← and this
        Rounds/Round.cpp
        Rounds/Turns/Turn.cpp

        # story driver
        MatamStory.cpp
        maintest.cpp
        Players/Behiviors/Behivior.cpp
        Players/Behiviors/Behivior.cpp


)

# create a convenient `run_test1` target


