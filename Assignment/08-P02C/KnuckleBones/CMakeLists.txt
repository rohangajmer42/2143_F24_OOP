cmake_minimum_required(VERSION 3.10)
project(KnuckleBones)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add the executable
add_executable(KnuckleBones main.cpp Dice.cpp Game.cpp Grid.cpp Player.cpp Button.cpp ScoreManager.cpp)

# Link SFML libraries
target_link_libraries(KnuckleBones sfml-system sfml-window sfml-graphics sfml-audio)
