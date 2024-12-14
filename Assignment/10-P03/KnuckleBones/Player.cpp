#include "Player.hpp"

// Default constructor (required for std::array)
Player::Player() : name("Unnamed"), scoreManager() {}

// Parameterized constructor
Player::Player(const std::string &name) : name(name), scoreManager()
{
    scoreManager.setPlayerName(name); // Set player name in ScoreManager
}

// Add points to the player's score
void Player::addToScore(int points)
{
    scoreManager.addScore(points);
}

// Get the player's score
int Player::getScore() const
{
    return scoreManager.getScore();
}

// Get the player's name
std::string Player::getName() const
{
    return name;
}

// Set the player's ScoreManager
void Player::setScoreManager(const ScoreManager &manager)
{
    scoreManager = manager;
}

// Get the player's ScoreManager (non-const)
ScoreManager &Player::getScoreManager()
{
    return scoreManager;
}

// Get the player's ScoreManager (const)
const ScoreManager &Player::getScoreManager() const
{
    return scoreManager;
}
