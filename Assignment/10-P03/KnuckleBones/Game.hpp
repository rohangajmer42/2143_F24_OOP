#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Include SFML Audio module
#include <array>
#include "Player.hpp"
#include "Grid.hpp"
#include "Dice.hpp"
#include "Button.hpp"
#include "ScoreManager.hpp"

class Game
{
public:
    Game(); // Constructor

    // Main game loop
    void run();

private:
    // Core SFML elements
    sf::RenderWindow window;
    sf::Font font;

    // Sound elements
    sf::SoundBuffer diceRollBuffer; // Buffer to hold dice roll sound
    sf::Sound diceRollSound;        // Sound to play dice roll

    // Game components
    Dice dice;
    std::array<Grid, 2> grids;     // Two 3x3 grids
    std::array<Player, 2> players; // Two players

    // Game state variables
    int currentPlayerIndex;
    int rolledValue;           // Holds the value of the rolled dice
    bool diceRolled = false;   // Flag to track if the dice was rolled
    bool diceRendered = false; // Flag to track if the dice should be rendered

    // Buttons
    Button rollButton;
    Button restartButton;
    Button exitButton;

    // Game state
    enum class GameState
    {
        Playing,
        GameOver
    } gameState;

    sf::Text gameOverText;

    // Core game functions
    void handleEvents();
    void update();
    void render();

    // Game logic
    bool isGameOver() const;
    void handleScoring(int col, int rolledValue);
    void displayWinner();
    void restartGame();
    void switchTurn();
};
