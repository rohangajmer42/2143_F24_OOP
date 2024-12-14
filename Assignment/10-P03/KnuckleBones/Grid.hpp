#pragma once
#include <SFML/Graphics.hpp>
#include <array>

class Grid {
public:
    Grid();
    Grid(float x, float y);
    bool placeDice(int col, int value);
    int getCellValue(int row, int col) const;
    void clearCell(int row, int col);
    void render(sf::RenderWindow& window, sf::Font& font, bool isActive) const;

private:
    std::array<std::array<int, 3>, 3> cells{};
    float startX, startY;
};
