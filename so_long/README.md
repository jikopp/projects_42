# so_long

so_long is a simple 2D game developed using the MiniLibX graphics library. The player navigates through a map, collecting coins and reaching an exit while avoiding obstacles.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Project Structure](#project-structure)
- [Map Validation](#map-validation)
- [Cleanup & Exit](#cleanup--exit)

---

## Overview
This project is part of the 42 School curriculum and is designed to reinforce understanding of:
- File handling and parsing.
- Game loops and event handling with MiniLibX.
- Memory management and error handling.

The game loads a `.ber` map file and renders a window where the player can move around, collect coins (`C`), and reach the exit (`E`) while avoiding walls (`1`).

## Features
- **2D Map Rendering**: Uses MiniLibX to display the game world.
- **Player Movement**: Move using `WASD` keys.
- **Item Collection**: Collect all coins to unlock the exit.
- **Win Condition**: Reach the exit after collecting all coins.
- **Map Validation**: Ensures the map is properly structured.
- **Memory Management**: Frees all allocated resources on exit.

## Installation
### Requirements
- A Unix-based system (Linux or macOS).
- MiniLibX installed.
- A valid map file (`.ber`).

### Compilation
Run the following command:
```sh
make
```
This generates the `so_long` executable.

## How to Play
1. Run the game with a valid `.ber` map:
   ```sh
   ./so_long maps/map.ber
   ```
2. Use the following controls:
   - `W`: Move Up
   - `A`: Move Left
   - `S`: Move Down
   - `D`: Move Right
   - `Esc`: Quit Game
3. Collect all coins (`C`) before heading to the exit (`E`).
4. Avoid walls (`1`), as you cannot move through them.

---

## Project Structure
### **Header File (`window.h`)**
Defines all structures and function prototypes.

#### **Structures**
- `t_player`: Stores player-related graphics.
- `t_textures`: Holds images for ground, coins, door, and walls.
- `t_win`: Manages the game state, including MLX pointers, score, move count, and map dimensions.

#### **Key Functions**
- **Event Handling**: `key_hook`, `on_destroy`
- **Player Movement**: `move_top`, `move_down`, `move_left`, `move_right`
- **Map Management**: `save_map`, `fill_map`, `check_map`
- **Rendering**: `put_player`, `add_graphics`
- **Memory Management**: `free_map`, `free_player`, `free_textures`

### **Controllers (`controllers.c`)**
Handles player movement.
- `put_player()`: Places the player at the correct position.
- `move_*()`: Checks movement rules, updates position, and handles collisions with walls, coins, and exits.

### **Door Lock (`door_lock.c`)**
Prevents players from passing through doors unless all coins are collected.

### **Memory Cleanup (`free_game.c`)**
Frees allocated resources to prevent memory leaks.
- `free_map()`, `free_player()`, `free_textures()`

### **Game Initialization (`main.c`)**
- Validates input and initializes the MLX window.
- Loads textures and sets up event hooks.
- Runs the game loop.
- Calls `on_destroy()` to free resources upon exit.

### **Map Validation (`map_check.c` & `map_check2.c`)**
Ensures the `.ber` map follows required rules:
- Must be enclosed by walls.
- Must contain at least one `P` (Player), `E` (Exit), and `C` (Coin).
- Uses flood fill algorithm to verify playability.

## Cleanup & Exit
The game cleans up allocated memory and destroys MLX objects when:
- The player quits using `Esc`.
- The game ends (win or manual exit).
- `on_destroy()` is triggered.

---

## License
This project follows the 42 School norms and is meant for educational purposes.

