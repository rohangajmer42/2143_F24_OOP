# P01 - KnuckleBones

### Rohan Gajmer

KnuckleBones is a C++ game project featuring dice rolling, player management, score tracking, and interactive gameplay through a simple UI. It uses a modular structure with cleanly separated game logic components.

---

## Files

|   #   | File                          | Description                        |
| :---: | ------------------------------ | ---------------------------------- |
|   1   | CMakeLists.txt                | Build configuration file.         |
|   2   | main.cpp                      | Entry point of the game.          |
|   3   | Button.cpp / Button.hpp       | Manages the button UI system.     |
|   4   | Dice.cpp / Dice.hpp           | Implements dice logic.            |
|   5   | Game.cpp / Game.hpp           | Core game logic and rules.        |
|   6   | Grid.cpp / Grid.hpp           | Manages the game grid.            |
|   7   | Player.cpp / Player.hpp       | Handles player data tracking.     |
|   8   | ScoreManager.cpp / ScoreManager.hpp | Calculates and tracks scores. |
|   9   | .vscode/                     | Project settings for VSCode.     |
|  10   | .gitignore                    | Excludes unwanted files.          |
|  11   | README.md                     | Project documentation.            |

---



## Features

- **Player Management:** Supports multiple players in competitive gameplay.
- **Dice Mechanics:** Implements random dice rolling.
- **Grid System:** Manages game grids dynamically.
- **Score Tracking:** Tracks and updates scores in real-time.
- **Interactive UI:** Simple button-based user interface.

---

## Installation

### Prerequisites
- **C++ Compiler** (GCC/Clang)
- **CMake** (Version 3.10 or higher)
- **Git** (For cloning the repository)

### Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/Rohangajmer42/KnuckleBones.git
   ```

2. **Build the Project**
   ```bash
   cd KnuckleBones
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Game**
   ```bash
   ./KnuckleBones
   ```

---

## Technologies Used

- **C++**: Core programming language
- **CMake**: Build automation tool
- **Git**: Version control system
- **VSCode**: Recommended IDE for development

---

3. **Common Errors:**
   - Missing C++ compiler installation.
   - Incorrect CMake version.
   - Missing external libraries such as SFML.
   - File path issues: Ensure relative paths are used correctly.

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
