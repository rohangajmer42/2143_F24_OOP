#pragma once
#include <SFML/Graphics.hpp>
#include <functional> // For std::function

class Dice
{
public:
    Dice();

    // Roll the dice and return a value between 1 and 6
    int roll();

    // Perform a dice-rolling animation and return the final value
    // Added a callback for rendering the game state
    int rollAnimation(sf::RenderWindow &window, sf::Font &font, float x, float y, std::function<void()> renderGame);

    // Render the last rolled dice face
    void renderLastRolled(sf::RenderWindow &window, float x, float y);

private:
    int currentValue;    // Stores the current rolled value
    int lastRolledValue; // Stores the last rolled value for display

    // Helper function to draw a dice face with dots
    void drawDiceFace(sf::RenderWindow &window, int value, float x, float y);
};
