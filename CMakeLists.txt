cmake_minimum_required(VERSION 3.29)
project(mtam_hw4)

set(CMAKE_CXX_STANDARD 14)

target_include_directories(mtam_hw4
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}  # makes `mtam-hw4/` an include root
)
add_executable(mtam_hw4

        main.cpp
        mainRound.cpp
        maintest.cpp
        Utilities.h
        MatamStory.cpp
        Utilities.cpp
        Players/Player.h
        Players/Player.cpp
        Players/Charactor.cpp
        Players/PlayerFactory.cpp

      Events/Event.h
        # jobs
        Players/Jobs/Job.cpp
        # behaviors
        Players/Behiviors/Behivior.cpp
        LeaderBoard.cpp
        "Events/Event .cpp"
        Events/EventFactory.cpp
        "Encounter/Encounter .cpp"
        Rounds/Round.cpp
        SpecialEvent/PotionsMerchant.cpp
        SpecialEvent/SolarEclipse.cpp
        SpecialEvent/SpecialEvent.cpp
        Turns/Turn.cpp
        Players/Charactor.h
        Events/EventFactory.h

)