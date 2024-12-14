#include "ScoreManager.hpp"

// Constructor: Initializes the player's score and name
ScoreManager::ScoreManager() : currentScore(0), playerName("Unnamed Player") {}

// Add points to the current score
void ScoreManager::addScore(int points)
{
    if (points < 0)
    {
        // Prevent negative scoring (optional safeguard)
        std::cerr << "Error: Cannot add negative points to score.\n";
        return;
    }
    currentScore += points;
}

// Get the current score
int ScoreManager::getScore() const
{
    return currentScore;
}

// Reset the player's score to 0
void ScoreManager::resetScore()
{
    currentScore = 0;
}

// Set the player's name
void ScoreManager::setPlayerName(const std::string &name)
{
    if (name.empty())
    {
        std::cerr << "Warning: Player name cannot be empty. Using default name.\n";
        playerName = "Unnamed Player";
    }
    else
    {
        playerName = name;
    }
}

// Get the player's name
std::string ScoreManager::getPlayerName() const
{
    return playerName;
}

// Debug function to display current score and player name (optional)
void ScoreManager::debugDisplay() const
{
    std::cout << "Player Name: " << playerName << ", Current Score: " << currentScore << "\n";
}
