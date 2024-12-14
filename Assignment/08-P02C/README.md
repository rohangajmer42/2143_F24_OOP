# 08-P02C - KnuckleBones (using Ncurces)

### Rohan Gajmer

## Overview

KnuckleBones is a two-player dice game implemented using the `ncurses` library. The objective is to score more points than your opponent by strategically placing dice in a 3x3 grid. This implementation is inspired by the game from *Cult of the Lamb* and adapted for console-based play.

---

## Rules

### Boards
- Each player has a 3x3 grid for placing dice.

### Turn Order
- Players alternate turns, rolling a 6-sided die and placing it in a column on their board.

### Dice Placement
- Dice are placed from the bottom up in a selected column.
- Columns that are full cannot accept more dice.

### Score Calculation
- Each column's score depends on dice values and their frequency:
  - Dice of the same value in a column multiply their value by the count of occurrences.
  - **Example:** A column with dice `4-1-4` scores:
    - `4x2 + 1x1 + 4x2 = 17`
  
### Opponent Dice Removal
- Placing a die removes all dice of the same value from the corresponding column on the opponent's grid.

### Game End
- The game ends when either player fills their grid.
- The player with the highest total score wins.

---

## Features

- **Dynamic Scoring:** Scores are updated after every turn with column-based multipliers.
- **Opponent Strategy:** Dice placement can remove opponent dice in the corresponding column.
- **Real-Time Updates:** Grids, scores, and current turns are updated dynamically.
- **Endgame Condition:** The winner is announced when a grid is completely filled.

---

## Controls

- **1:** Start a new game.
- **2:** Roll the dice.
- **3:** Exit the game.

### Column Selection
- After rolling, press `1`, `2`, or `3` to select a column for dice placement.

---

## Code Structure

### 1. Grid Class
Represents each player's 3x3 board.

**Key Methods:**
- `reset()` - Clears the grid.
- `place_dice(int col, int value)` - Places a die in a specified column.
- `remove_dice(int col, int value)` - Removes dice of a specific value from a column.
- `calculate_column_score(int col)` - Calculates the score for a single column.
- `calculate_total_score()` - Calculates the total score for the grid.
- `is_full()` - Checks if the grid is completely filled.

### 2. Game Class
Manages the overall game flow.

**Key Methods:**
- `start()` - Starts the game loop.
- `display_menu()` - Displays the game menu.
- `display_turn()` - Shows the current player's turn.
- `display_scores()` - Updates and shows the players' scores.
- `animate_dice_roll()` - Animates the dice rolling process.
- `handle_turn()` - Handles the current player's dice placement and score updates.
- `declare_winner()` - Declares the winner at the end of the game.

### 3. Main Function
- Initializes `ncurses` and starts the game loop by creating a `Game` instance.

---

## How to Run

1. **Compile the Code:**
   ```bash
   g++ -o knucklebones_game knucklebones_game.cpp -lncurses
   ```

2. **Run the Game:**
   ```bash
   ./knucklebones_game
   ```

3. **Follow On-Screen Instructions:** Play the game using the provided controls.

---

## Future Enhancements

- Add support for AI opponents.
- Include additional difficulty levels.
- Add a graphical interface using a more advanced library.

---

## Credits

- **Developer:** Adapted by [Your Name]
- **Inspired by:** *Cult of the Lamb*
