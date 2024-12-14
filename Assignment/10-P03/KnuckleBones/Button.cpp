#include "Button.hpp"
#include <iostream>

Button::Button(const std::string& text, sf::Font& font, float x, float y, float width, float height) {
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(sf::Color(200, 200, 200)); // Light gray
    buttonShape.setOutlineThickness(2);
    buttonShape.setOutlineColor(sf::Color::Black);

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(20);
    buttonText.setFillColor(sf::Color::Black);

    // Center the text inside the button
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setPosition(
        x + (width - textBounds.width) / 2 - textBounds.left,
        y + (height - textBounds.height) / 2 - textBounds.top
    );
}

void Button::render(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Vector2i& mousePos) {
    sf::FloatRect bounds = buttonShape.getGlobalBounds();
    bool clicked = bounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    std::cout << "Button bounds: (" << bounds.left << ", " << bounds.top 
              << ", " << bounds.width << ", " << bounds.height << ") | "
              << "Mouse Pos: (" << mousePos.x << ", " << mousePos.y << ") | "
              << "Clicked: " << (clicked ? "true" : "false") << std::endl;
    return clicked;
}


void Button::setOnClick(std::function<void()> callback) {
    std::cout << "setOnClick called!" << std::endl; // Debug: Ensure this is being executed
    onClick = callback;
}

std::function<void()> Button::getOnClick() const {
    return onClick;
}

