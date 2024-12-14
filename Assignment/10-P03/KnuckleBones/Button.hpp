#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(const std::string& text, sf::Font& font, float x, float y, float width, float height);

    void render(sf::RenderWindow& window); // Renders the button
    bool isClicked(const sf::Vector2i& mousePos); // Checks if the button is clicked
    void setOnClick(std::function<void()> callback); // Sets the button's action
    std::function<void()> getOnClick() const;


private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    std::function<void()> onClick; // Action to perform when the button is clicked
    
};
