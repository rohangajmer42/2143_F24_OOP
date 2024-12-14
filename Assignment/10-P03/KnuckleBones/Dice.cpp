#include "Dice.hpp"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <array>

Dice::Dice()
    : lastRolledValue(1) // Initialize with a default value
{
    // Initialize random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

// Roll the dice and return a random number from 1 to 6
int Dice::roll()
{
    currentValue = (std::rand() % 6) + 1;
    lastRolledValue = currentValue; // Update the last rolled value
    return currentValue;
}

// Helper function to draw dice dots based on the value
void Dice::drawDiceFace(sf::RenderWindow &window, int value, float x, float y)
{
    sf::RectangleShape diceFace(sf::Vector2f(100, 100));
    diceFace.setPosition(x - 50, y - 50);
    diceFace.setFillColor(sf::Color::White);
    diceFace.setOutlineThickness(5);
    diceFace.setOutlineColor(sf::Color::Black);
    window.draw(diceFace);

    // Positions for dots
    std::array<sf::Vector2f, 7> dotPositions = {
        sf::Vector2f(x, y),           // Center
        sf::Vector2f(x - 25, y - 25), // Top-left
        sf::Vector2f(x + 25, y + 25), // Bottom-right
        sf::Vector2f(x - 25, y + 25), // Bottom-left
        sf::Vector2f(x + 25, y - 25), // Top-right
        sf::Vector2f(x - 25, y),      // Left-center
        sf::Vector2f(x + 25, y)       // Right-center
    };

    // Draw dots based on the dice value
    auto drawDot = [&](sf::Vector2f position)
    {
        sf::CircleShape dot(8); // Dot radius
        dot.setFillColor(sf::Color::Black);
        dot.setPosition(position.x - dot.getRadius(), position.y - dot.getRadius());
        window.draw(dot);
    };

    switch (value)
    {
    case 1:
        drawDot(dotPositions[0]); // Center
        break;
    case 2:
        drawDot(dotPositions[1]); // Top-left
        drawDot(dotPositions[2]); // Bottom-right
        break;
    case 3:
        drawDot(dotPositions[0]); // Center
        drawDot(dotPositions[1]); // Top-left
        drawDot(dotPositions[2]); // Bottom-right
        break;
    case 4:
        drawDot(dotPositions[1]); // Top-left
        drawDot(dotPositions[2]); // Bottom-right
        drawDot(dotPositions[3]); // Bottom-left
        drawDot(dotPositions[4]); // Top-right
        break;
    case 5:
        drawDot(dotPositions[0]); // Center
        drawDot(dotPositions[1]); // Top-left
        drawDot(dotPositions[2]); // Bottom-right
        drawDot(dotPositions[3]); // Bottom-left
        drawDot(dotPositions[4]); // Top-right
        break;
    case 6:
        drawDot(dotPositions[1]); // Top-left
        drawDot(dotPositions[2]); // Bottom-right
        drawDot(dotPositions[3]); // Bottom-left
        drawDot(dotPositions[4]); // Top-right
        drawDot(dotPositions[5]); // Left-center
        drawDot(dotPositions[6]); // Right-center
        break;
    }
}

// Perform a dice-rolling animation
int Dice::rollAnimation(sf::RenderWindow &window, sf::Font &font, float x, float y, std::function<void()> renderGame)
{
    // Animate the dice rolling
    for (int i = 0; i < 15; ++i)
    {
        int randomValue = (std::rand() % 6) + 1;

        // Render the game state first
        renderGame();

        // Overlay the dice animation
        drawDiceFace(window, randomValue, x, y);
        window.display();

        // Pause for animation effect
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Final roll
    int finalValue = roll();

    // Render the final dice value
    renderGame();
    drawDiceFace(window, finalValue, x, y);
    window.display();

    return finalValue;
}

// Render the last rolled dice
void Dice::renderLastRolled(sf::RenderWindow &window, float x, float y)
{
    drawDiceFace(window, lastRolledValue, x, y);
}
