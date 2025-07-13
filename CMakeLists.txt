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
        Players/Behiviors/Behivior.cpp

        # jobs  ← you must have this
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




)
enable_testing()

# create a convenient `run_test1` target
add_custom_target(run_test1
        COMMAND $<TARGET_FILE:mtam_hw4> test1
        DEPENDS mtam_hw4
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
)

# register it with CTest so CLion’s “Run” button works
add_test(NAME test1
        COMMAND mtam_hw4 test1
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tests
)