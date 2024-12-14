// KnuckleBones Game - Program 2C
// using Ncurces

#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <map>
using namespace std;

// Grid class definition
class Grid
{
public:
    static const int ROWS = 3;
    static const int COLS = 3;
    int cells[ROWS][COLS];

    Grid()
    {
        reset();
    }

    void reset()
    {
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                cells[i][j] = 0;
            }
        }
    }

    bool place_dice(int col, int value)
    {
        for (int i = ROWS - 1; i >= 0; --i)
        {
            if (cells[i][col] == 0)
            {
                cells[i][col] = value;
                return true;
            }
        }
        return false;
    }

    void remove_dice(int col, int value)
    {
        for (int i = 0; i < ROWS; ++i)
        {
            if (cells[i][col] == value)
            {
                cells[i][col] = 0;
            }
        }
    }

    void display(int start_y, int start_x) const
    {
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                mvprintw(start_y + i, start_x + j * 4, "[%d]", cells[i][j]);
            }
        }
        refresh();
    }

    int calculate_column_score(int col) const
    {
        map<int, int> frequency;
        for (int i = 0; i < ROWS; ++i)
        {
            if (cells[i][col] > 0)
            {
                frequency[cells[i][col]]++;
            }
        }

        int score = 0;
        for (const auto &[value, count] : frequency)
        {
            score += value * count * count; // Apply multiplier
        }
        return score;
    }

    int calculate_total_score() const
    {
        int total = 0;
        for (int col = 0; col < COLS; ++col)
        {
            total += calculate_column_score(col);
        }
        return total;
    }

    bool is_full() const
    {
        for (int col = 0; col < COLS; ++col)
        {
            if (cells[0][col] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Game class definition
class Game
{
public:
    Grid player1Grid;
    Grid player2Grid;
    bool diceRolled;
    int rolledValue;
    int currentPlayerIndex;

    Game() : diceRolled(false), rolledValue(0), currentPlayerIndex(0) {}

    void display_menu()
    {
        mvprintw(14, 2, "1. Start New Game");
        mvprintw(15, 2, "2. Roll Dice");
        mvprintw(16, 2, "3. Exit");
        refresh();
    }

    void display_turn()
    {
        mvprintw(13, 2, "Current Turn: Player %d", currentPlayerIndex + 1);
        refresh();
    }

    void display_scores()
    {
        mvprintw(18, 2, "Player 1 Total Score: %d", player1Grid.calculate_total_score());
        mvprintw(19, 2, "Player 2 Total Score: %d", player2Grid.calculate_total_score());
        refresh();
    }

    void display_grid_titles()
    {
        mvprintw(1, 2, "Player 1");
        mvprintw(7, 2, "Player 2");
        refresh();
    }

    void animate_dice_roll()
    {
        int y = LINES / 2;
        int x = COLS / 2;
        for (int i = 0; i < 6; ++i)
        {
            rolledValue = (rand() % 6) + 1;
            mvprintw(y, x, "Rolling: %d   ", rolledValue); // Clear previous value with spaces
            refresh();
            usleep(200000); // Delay for animation
        }
        mvprintw(y, x, "Final Roll: %d   ", rolledValue); // Display final roll only
        refresh();
        diceRolled = true;
        handle_turn(); // Automatically ask player to choose a column after rolling
    }

    void handle_turn()
    {
        mvprintw(20, 2, "Player %d, choose a column (1-3): ", currentPlayerIndex + 1);
        int col = getch() - '1'; // Adjust to interpret input as 1-based index

        if (col >= 0 && col < Grid::COLS)
        {
            Grid &currentGrid = (currentPlayerIndex == 0) ? player1Grid : player2Grid;
            Grid &opponentGrid = (currentPlayerIndex == 0) ? player2Grid : player1Grid;

            if (currentGrid.place_dice(col, rolledValue))
            {
                opponentGrid.remove_dice(col, rolledValue); // Remove opponent's dice
                diceRolled = false;
                player1Grid.display(2, 2);
                player2Grid.display(8, 2);
                display_scores();

                if (currentGrid.is_full())
                {
                    declare_winner();
                    return;
                }

                currentPlayerIndex = (currentPlayerIndex + 1) % 2;
                display_turn();
            }
            else
            {
                mvprintw(21, 2, "Column is full! Try another column.");
                refresh();
                handle_turn(); // Retry
            }
        }
        else
        {
            mvprintw(21, 2, "Invalid column. Try again.");
            refresh();
            handle_turn(); // Retry
        }
    }

    void declare_winner()
    {
        int player1Score = player1Grid.calculate_total_score();
        int player2Score = player2Grid.calculate_total_score();

        clear();
        if (player1Score > player2Score)
        {
            mvprintw(LINES / 2, (COLS / 2) - 10, "Player 1 Wins with %d points!", player1Score);
        }
        else if (player2Score > player1Score)
        {
            mvprintw(LINES / 2, (COLS / 2) - 10, "Player 2 Wins with %d points!", player2Score);
        }
        else
        {
            mvprintw(LINES / 2, (COLS / 2) - 5, "It's a Tie!");
        }
        refresh();
        getch();
        endwin();
        exit(0);
    }

    void start()
    {
        printw("Welcome to KnuckleBones!\n");
        refresh();

        display_grid_titles();
        player1Grid.display(2, 2);
        player2Grid.display(8, 2);
        display_menu();
        display_turn();
        display_scores();

        int choice;
        while (true)
        {
            choice = getch();
            switch (choice)
            {
            case '1':
                player1Grid.reset();
                player2Grid.reset();
                display_grid_titles();
                player1Grid.display(2, 2);
                player2Grid.display(8, 2);
                diceRolled = false;
                currentPlayerIndex = 0;
                display_turn();
                display_scores();
                break;
            case '2':
                animate_dice_roll();
                break;
            case '3':
                endwin();
                exit(0);
            }
        }
    }
};

// Main function
int main()
{
    // Initialize ncurses
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();

    // Create and start the game
    Game game;
    game.start();

    // End ncurses session
    endwin();
    return 0;
}
