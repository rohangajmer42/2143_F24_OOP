#pragma once

#include <string>
#include <iostream> // For debug output

class ScoreManager
{
public:
    // Constructor
    ScoreManager();

    // Score Management
    void addScore(int points); // Add points to the current score
    int getScore() const;      // Get the current score
    void resetScore();         // Reset the score to 0

    // Player Metadata Management
    void setPlayerName(const std::string &name); // Set the player's name
    std::string getPlayerName() const;           // Get the player's name

    // Debug Function
    void debugDisplay() const; // Display player details (for debugging)

private:
    std::string playerName; // Holds the player's name
    int currentScore;       // Holds the player's score
};
