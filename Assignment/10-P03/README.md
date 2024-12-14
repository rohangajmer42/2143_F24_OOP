# KnuckleBones Game using SFML

## Project Overview

KnuckleBones is a console-based game inspired by the dice game from 'Cult of the Lamb.' Players roll dice, place them strategically on a grid, and score points based on matching numbers in rows and columns.

## Installation and Setup

### System Requirements

- C++17 compiler (GCC, Clang, MSVC)
- CMake 3.10+

### Build Instructions

1. Clone the repository:
   ```bash
   git clone <(https://github.com/rohangajmer42/2143_F24_OOP/tree/main/Assignment/10-P03/KnuckleBones)>
   cd KnuckleBones
   ```
2. Create a build directory and run CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Run the game:
   ```bash
   ./KnuckleBones
   ```

### Optional: Using VcXsrv

If you want to run the game with VcXsrv, use the following command:

```bash
vcxsrv.exe :0 -ac -wgl -multiwindow -clipboard
```

## Directory Structure

```
KnuckleBones/
├── assets/            # Game assets (textures, sounds, etc.)
├── build/             # Build directory
├── src/               # Source files
├── CMakeLists.txt     # Build configuration
└── README.md          # Project documentation
```

## Code Documentation

### Core Classes

#### 1. `Game`

- Manages the overall game flow, game states, and interactions.

#### 2. `Player`

- Tracks player statistics such as score and dice rolls.

#### 3. `Dice`

- Implements random dice rolls and dice representation.

#### 4. `Grid`

- Manages the game board and handles placement logic.

#### 5. `Button`

- Provides functionality for UI buttons.

#### 6. `ScoreManager`

- Calculates and updates the player's score based on game rules.

### Main Program

- `main.cpp`: The entry point for the application, initializing game components and starting the main loop.

## Files

| # | File               | Description                               |
| - | ------------------ | ----------------------------------------- |
| 1 | `main.cpp`         | Main driver of the project.               |
| 2 | `Game.cpp`         | Contains game logic and flow management.  |
| 3 | `Player.cpp`       | Manages player stats and actions.         |
| 4 | `Dice.cpp`         | Implements dice rolls and random numbers. |
| 5 | `Grid.cpp`         | Manages the game board and tile states.   |
| 6 | `Button.cpp`       | Implements UI button functionality.       |
| 7 | `ScoreManager.cpp` | Handles score calculations and updates.   |

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
- Example: A column with dice 4-1-4 scores:
  - 4x2 + 1x1 + 4x2 = 17

### Opponent Dice Removal

- Placing a die removes all dice of the same value from the corresponding column on the opponent's grid.

### Game End

- The game ends when either player fills their grid.
- The player with the highest total score wins.

## Instructions

- Ensure you have all required libraries installed.
- Build and compile the project using the provided CMake instructions.
- Use the command `./KnuckleBones` to run the game.
- If using Windows and needing graphical support, consider using VcXsrv.

## Common Errors

- **Local Library Issues**: Ensure required libraries are installed and linked.
- **Pathing Errors**: Use relative paths for assets to avoid hardcoding issues.
- **Filename Mismatches**: Ensure correct filenames when accessing external files.

## Assets and Resources

- All game-related assets such as textures and sound effects are located in the `assets/` directory.


## GitHub Repository

You can find the official repository for this project at the following link:

[KnuckleBones GitHub Repository](https://github.com/rohangajmer42/2143_F24_OOP/tree/main/Assignment/10-P03/KnuckleBones)

## Credits

- Developer: Adapted by [Rohan Gajmer]
- Inspired by: Cult of the Lamb

---

Enjoy playing KnuckleBones!


---

## Project Structure

```
KnuckleBones/
│
├── CMakeLists.txt               # Build configuration
├── main.cpp                     # Entry point
│
├── Button.cpp / Button.hpp      # Button UI system
├── Dice.cpp / Dice.hpp          # Dice logic
├── Game.cpp / Game.hpp          # Core game logic
├── Grid.cpp / Grid.hpp          # Grid management
├── Player.cpp / Player.hpp      # Player data tracking
├── ScoreManager.cpp / ScoreManager.hpp # Score calculation
│
├── .vscode/                     # VSCode project setup
├── .gitignore                   # Ignore unwanted files
└── README.md                    # Project documentation
```



---
