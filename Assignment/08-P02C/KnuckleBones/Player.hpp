#pragma once

#include <string>
#include "ScoreManager.hpp"

class Player
{
public:
    Player();                        // Default constructor (required for std::array)
    Player(const std::string &name); // Constructor with player name

    // Methods to interact with the score manager
    void setScoreManager(const ScoreManager &manager);
    ScoreManager &getScoreManager();             // Return a reference to the ScoreManager
    const ScoreManager &getScoreManager() const; // Const version

    // Methods for score and name convenience
    void addToScore(int points);
    int getScore() const;
    std::string getName() const;

private:
    std::string name;
    ScoreManager scoreManager; // Embedded ScoreManager instance
};
