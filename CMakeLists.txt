cmake_minimum_required(VERSION 3.29)
project(mtam_hw4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Events)
include_directories(Players)

add_executable(mtam_hw4
    Events/Event.h
    Players/Player.h
    main.cpp
    MatamStory.cpp
    MatamStory.h
    Utilities.cpp
    Utilities.h
<<<<<<< HEAD
        Rounds/Round.h
        Rounds/Round.cpp
        Turns/Turn.h
        Events/SpecialEvent.h
        Events/Encounter.h
        Enemy/Enemy.h
        Leaderboard.h
        Turns/Turn.cpp
        "Events/Event .cpp"
        "Events/Encounter .cpp"
        Events/SpecialEvent.cpp
        Leaderboard.h)
=======
        Players/PlayerFactory.h
        Players/Charactor.h
        Players/Jobs/Job.h
        Players/Jobs/Warrior.h
        Players/Jobs/Archer.h
        "Players/Jobs/Magician .h"
        Players/Player.cpp
        Players/Jobs/Job.cpp
        Players/Behiviors/Behivior.h
        Players/Behiviors/Responsible.h
        Players/Behiviors/RiskTaking.h
        Players/Behiviors/Behivior.cpp
        Players/Charactor.cpp
        Players/PlayerFactory.cpp
        maintest.cpp
        maintest.cpp
)
