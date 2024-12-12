#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

// Add this at the top of Game.cpp
float lastDiceX; // Position X of the last rolled dice
float lastDiceY; // Position Y of the last rolled dice

Game::Game()
    : window(sf::VideoMode(800, 600), "KnuckleBones"),
      currentPlayerIndex(0),
      rollButton("Roll Dice", font, 300, 500, 200, 50),
      restartButton("Restart", font, 100, 500, 200, 50),
      exitButton("Exit", font, 500, 500, 200, 50),
      gameState(GameState::Playing),
      diceRendered(false) // Initialize diceRendered
{
    if (!font.loadFromFile("assets/fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font from assets/fonts/arial.ttf" << std::endl;
        exit(1);
    }

    // Initialize players
    players[0] = Player("Player 1");
    players[1] = Player("Player 2");

    // Initialize grids
    grids[0] = Grid(100, 100);
    grids[1] = Grid(500, 100);

    // Initialize game-over text
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(200, 150);
    gameOverText.setString("");

    // Set onClick actions for buttons
    rollButton.setOnClick([this]()
                          {
        if (!diceRolled)
        {
            float grid1_x = 100;
            float grid2_x = 500;
            float dice_center_x = (grid1_x + grid2_x) / 2 + 80;
            float dice_center_y = 200;

            rolledValue = dice.rollAnimation(window, font, dice_center_x, dice_center_y, [this]() {
                window.clear(sf::Color(0, 100, 200));
                render();
            });

            lastDiceX = dice_center_x;
            lastDiceY = dice_center_y;

            diceRolled = true;
            diceRendered = true; // Set diceRendered to true
        } });

    restartButton.setOnClick([this]()
                             { restartGame(); });
    exitButton.setOnClick([this]()
                          { window.close(); });
}

void Game::run()
{
    while (window.isOpen())
    {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (rollButton.isClicked(mousePos))
            {
                rollButton.getOnClick()();
                return;
            }
            if (restartButton.isClicked(mousePos))
            {
                restartButton.getOnClick()();
                return;
            }
            if (exitButton.isClicked(mousePos))
            {
                exitButton.getOnClick()();
                return;
            }

            if (gameState == GameState::Playing && diceRolled)
            {
                for (int col = 0; col < 3; ++col)
                {
                    float gridX = (currentPlayerIndex == 0 ? 100 : 500) + col * 70;

                    if (mousePos.x >= gridX && mousePos.x <= gridX + 60)
                    {
                        if (grids[currentPlayerIndex].placeDice(col, rolledValue))
                        {
                            handleScoring(col, rolledValue);
                            diceRolled = false;
                            switchTurn();
                        }
                        return;
                    }
                }
            }
        }
    }
}

void Game::update()
{
    if (gameState == GameState::Playing && isGameOver())
    {
        displayWinner();
        gameState = GameState::GameOver;
    }
}

void Game::render()
{
    window.clear(sf::Color(0, 100, 200));

    if (gameState == GameState::Playing)
    {
        // Title
        sf::Text title("KnuckleBones Game", font, 48);
        title.setPosition(200, 20);
        title.setFillColor(sf::Color::White);
        window.draw(title);

        // Render grids
        grids[0].render(window, font, currentPlayerIndex == 0);
        grids[1].render(window, font, currentPlayerIndex == 1);

        // Render player scores
        sf::Text player1Score(players[0].getName() + ": " + std::to_string(players[0].getScore()), font, 24);
        player1Score.setPosition(100, 350);
        player1Score.setFillColor(sf::Color::White);
        window.draw(player1Score);

        sf::Text player2Score(players[1].getName() + ": " + std::to_string(players[1].getScore()), font, 24);
        player2Score.setPosition(500, 350);
        player2Score.setFillColor(sf::Color::White);
        window.draw(player2Score);

        // Display whose turn it is
        sf::Text turnText("Turn: " + players[currentPlayerIndex].getName(), font, 24);
        turnText.setPosition(300, 450);
        turnText.setFillColor(sf::Color::Yellow);
        window.draw(turnText);

        // Render the dice only if it has been rolled
        if (diceRendered)
        {
            dice.renderLastRolled(window, lastDiceX, lastDiceY);
        }

        // Render buttons
        rollButton.render(window);
        restartButton.render(window);
        exitButton.render(window);
    }
    else if (gameState == GameState::GameOver)
    {
        window.draw(gameOverText);
        restartButton.render(window);
        exitButton.render(window);
    }

    window.display();
}

bool Game::isGameOver() const
{
    for (int i = 0; i < 2; ++i) // Check both players' grids
    {
        bool isGridFull = true;
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (grids[i].getCellValue(row, col) == 0) // Check for any empty cell
                {
                    isGridFull = false;
                    break;
                }
            }
            if (!isGridFull)
                break;
        }

        if (isGridFull)
        {
            return true; // If either player's grid is full, the game is over
        }
    }
    return false; // Game is not over if neither grid is full
}

void Game::displayWinner()
{
    int player1Score = players[0].getScore();
    int player2Score = players[1].getScore();

    if (player1Score > player2Score)
    {
        gameOverText.setString("Game Over!\n" + players[0].getName() + " Wins with " + std::to_string(player1Score) + " points!");
    }
    else if (player2Score > player1Score)
    {
        gameOverText.setString("Game Over!\n" + players[1].getName() + " Wins with " + std::to_string(player2Score) + " points!");
    }
    else
    {
        gameOverText.setString("Game Over!\nIt's a Tie!");
    }
}

void Game::handleScoring(int col, int rolledValue)
{
    // Get the current player's grid and the opponent's grid
    Grid &currentGrid = grids[currentPlayerIndex];
    Grid &opponentGrid = grids[(currentPlayerIndex + 1) % 2];

    // Clear matching dice in the opponent's column
    for (int row = 0; row < 3; ++row)
    {
        if (opponentGrid.getCellValue(row, col) == rolledValue)
        {
            opponentGrid.clearCell(row, col); // Clear the dice
        }
    }

    // Recalculate the current player's score
    players[currentPlayerIndex].getScoreManager().resetScore(); // Reset the current player's score
    for (int c = 0; c < 3; ++c)
    {
        // Track the frequency of each value in the column
        std::map<int, int> frequency;

        for (int r = 0; r < 3; ++r)
        {
            int value = currentGrid.getCellValue(r, c);
            if (value > 0)
            {
                frequency[value]++;
            }
        }

        // Calculate the column score based on frequency
        for (int r = 0; r < 3; ++r)
        {
            int value = currentGrid.getCellValue(r, c);
            if (value > 0)
            {
                int multiplier = frequency[value];
                players[currentPlayerIndex].getScoreManager().addScore(value * multiplier);
            }
        }
    }

    // Recalculate the opponent's score
    players[(currentPlayerIndex + 1) % 2].getScoreManager().resetScore(); // Reset the opponent's score
    for (int c = 0; c < 3; ++c)
    {
        // Track the frequency of each value in the column
        std::map<int, int> frequency;

        for (int r = 0; r < 3; ++r)
        {
            int value = opponentGrid.getCellValue(r, c);
            if (value > 0)
            {
                frequency[value]++;
            }
        }

        // Calculate the column score based on frequency
        for (int r = 0; r < 3; ++r)
        {
            int value = opponentGrid.getCellValue(r, c);
            if (value > 0)
            {
                int multiplier = frequency[value];
                players[(currentPlayerIndex + 1) % 2].getScoreManager().addScore(value * multiplier);
            }
        }
    }
}

void Game::restartGame()
{
    // Reset grids
    grids[0] = Grid(100, 100);
    grids[1] = Grid(500, 100);

    // Reset scores
    players[0].getScoreManager().resetScore();
    players[1].getScoreManager().resetScore();

    // Reset game state
    currentPlayerIndex = 0;
    diceRolled = false;
    gameState = GameState::Playing;
    gameOverText.setString("");
}

void Game::switchTurn()
{
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}
