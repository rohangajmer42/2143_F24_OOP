# Knucklebones Game Design

## Overview
This document outlines the class structure for a digital version of the Knucklebones game, including the core components and newly suggested features. The new features add depth to the game and provide enhanced functionality for players.

## Class Design Structure

### Dice Class
**Attributes:**
- `sides`: Number of sides on the die (default = 6)
- `current_value`: The most recent value rolled on the die
- **NEW:** `type`: The type of dice (e.g., normal, weighted, negative, wildcard)

**Methods:**
- `roll()`: Roll the die to generate a random value between 1 and the number of sides.
- `get_value()`: Retrieve the current value of the die.
- **NEW:** `get_dice_type()`: Retrieve the type of the die.
- **NEW:** `apply_special_effect()`: Apply any special effect based on the dice type.

### Player Class
**Attributes:**
- `name`: The name of the player.
- `score`: Current score of the player.
- `grid`: A 3x3 matrix representing the player’s game grid.
- `dice_set`: A Dice object.
- `player_stats`: Statistics of the player’s performance.
- **NEW:** `abilities`: List of abilities the player can use (e.g., "Score Multiplier", "Column Swap").
- **NEW:** `ability_uses`: Number of remaining uses for each ability.
- **NEW:** `achievements`: List of unlocked achievements (e.g., "First Win", "Perfect Game").

**Methods:**
- `roll_dice()`: Roll a die to get its value.
- `place_dice(dice_value, column)`: Place the rolled die in a specific column on the player’s grid.
- `get_score()`: Calculate and retrieve the current score based on the grid’s state.
- `update_score()`: Update the score based on new dice placements.
- **NEW:** `use_ability(ability)`: Use a player-specific ability.
- **NEW:** `unlock_achievement(achievement)`: Unlock a new achievement for the player.
- **NEW:** `update_statistics(stat, value)`: Update a specific statistic for the player.

### Grid Class
**Attributes:**
- `columns`: A list containing three sublists representing each column on the grid.
- **NEW:** `special_slots`: Dictionary indicating special slots (e.g., traps, bonuses).

**Methods:**
- `add_dice(dice_value, column)`: Place the dice in the specified column.
- `remove_dice(dice_value, column)`: Remove a dice with a specified value from the column.
- `get_column_sum(column)`: Calculate and return the sum of a specific column.
- `get_total_score()`: Calculate the total score based on all columns.
- `check_full()`: Check if the grid is completely filled.
- **NEW:** `activate_slot_effect(column, row)`: Activate the effect based on the slot type (e.g., traps, multipliers).

### Game Class
**Attributes:**
- `players`: List of players participating in the game.
- `rules`: Basic rules of the game.
- `current_round`: The round number of the game.
- **NEW:** `game_mode`: The current game mode (e.g., "Classic", "Timed Mode", "Battle Mode").
- **NEW:** `time_limit`: Time limit for timed mode (if applicable).

**Methods:**
- `start_game()`: Initialize the game and set up players.
- `end_game()`: Conclude the game and determine if there’s a winner.
- `get_winner()`: Determine and return the player with the highest score.
- **NEW:** `select_game_mode(mode)`: Set the current game mode.
- **NEW:** `apply_game_mode_rules()`: Apply specific rules based on the game mode.

### Knucklebones Class (Inherits from Game)
**Attributes:**
- `board`: A 3x3 grid for each player.
- `knucklebones_specific_rules`: Additional rules specific to the Knucklebones variant.
- **NEW:** `leaderboard`: A list of top scores and player names.

**Methods:**
- `start_round()`: Start a new round of the game.
- `end_round()`: End the round and update the board states.
- `calculate_winner()`: Determine the winner based on scoring rules and dice placements.
- **NEW:** `update_leaderboard(player)`: Update the leaderboard with the player’s score.
- **NEW:** `display_leaderboard()`: Display the top scores in the leaderboard.

## New Feature Ideas Implemented

### Special Dice Variants
- Different types of dice such as Weighted Dice, Negative Dice, and Wildcard Dice that add complexity and strategy to the game.

### Player Abilities and Power-Ups
- Players have abilities like "Score Multiplier" and "Opponent Disruption" that they can use strategically.

### Grid Traps and Bonuses
- Special slots in the grid such as Trap Slots and Bonus Slots to enhance gameplay.

### Game Modes and Variants
- Different game modes like "Classic", "Timed Mode", and "Battle Mode" that change the game dynamics.

### Achievements and Stats Tracking
- Track achievements like "First Win", "Perfect Game", and more. Also, record detailed statistics for each player.

### Interactive AI Opponent
- AI players with different difficulty levels: Easy, Medium, and Hard.

### Leaderboard and High Scores
- Maintain a leaderboard to track the top scores and player names.

### Themes and Customization
- Add visual themes and customizations to personalize the look and feel of the game.
