#include "Grid.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// Default constructor (required for std::array)
Grid::Grid() : startX(0), startY(0) {
    for (auto& row : cells)
        row.fill(0);  // Initialize all cells to zero
}

// Parameterized constructor
Grid::Grid(float x, float y) : startX(x), startY(y) {
    for (auto& row : cells)
        row.fill(0);  // Initialize all cells to zero
}

// Place a dice value in a column if possible
bool Grid::placeDice(int col, int value) {
    for (int row = 2; row >= 0; --row) {
        if (cells[row][col] == 0) {
            cells[row][col] = value;
            return true;
        }
    }
    return false;  // Column is full
}

// Get value from a specific cell
int Grid::getCellValue(int row, int col) const {
    return cells[row][col];
}

// Clear a specific cell
void Grid::clearCell(int row, int col) {
    cells[row][col] = 0;
}

// Render the entire grid
void Grid::render(sf::RenderWindow& window, sf::Font& font, bool isActive) const {
    sf::RectangleShape cell(sf::Vector2f(60, 60));
    cell.setOutlineThickness(3);
    cell.setOutlineColor(isActive ? sf::Color::Yellow : sf::Color::White);

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cell.setPosition(startX + col * 70, startY + row * 70);
            cell.setFillColor(cells[row][col] != 0 ? sf::Color(150, 200, 255) : sf::Color::Transparent);
            window.draw(cell);

            // Draw dice value if the cell is occupied
            if (cells[row][col] != 0) {
                sf::Text valueText(std::to_string(cells[row][col]), font, 32);
                valueText.setPosition(cell.getPosition().x + 20, cell.getPosition().y + 10);
                valueText.setFillColor(sf::Color::Black);
                window.draw(valueText);
            }
        }
    }
}