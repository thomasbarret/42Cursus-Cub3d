# 42 Cursus - Cub3d

**Cub3d** is a 3D raycasting engine developed as part of the 42 Cursus. This project allows you to create a simple 3D world where the player can navigate using raycasting techniques. It is inspired by classic 3D games like Wolfenstein 3D, with a focus on implementing low-level graphics and understanding how 3D rendering works.

---

## Table of Contents

- [Requirements](#requirements)
- [Compilation and Usage](#compilation-and-usage)
- [Features](#features)
- [File Structure](#file-structure)
- [Map Format](#map-format)
- [Libraries](#libraries)

---

## Requirements

- GCC (GNU Compiler Collection)
- Make
- A Unix-based system (Linux/macOS recommended)
- MinilibX library for graphical rendering

---

## Compilation and Usage

To compile and run the project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/cub3d.git
   cd cub3d
   ```

2. To compile the project:
   ```bash
   make
   ```

3. To run the program:
   ```bash
   ./cub3d maps/map.cub
   ```

4. Navigate through the 3D world using the arrow keys and WASD for movement. You can quit the game by pressing the `ESC` key.

---

## Features

- **Raycasting**: A fundamental technique to render 3D environments in a 2D space, allowing the creation of a 3D world view.
- **Map Parsing**: Support for reading and parsing `.cub` map files which define the 3D world structure and layout.
- **Player Movement**: First-person player movement through the map with keyboard controls.
- **Texturing**: Ability to load and apply textures to walls in the 3D environment.
- **MinilibX**: Used for window management, graphics rendering, and handling user inputs.
- **Bonus Features**: Includes additional functionality such as enhanced player control and new map features (check `src_bonus`).

---

## File Structure

```
.
├── Makefile                    # Makefile to compile the project
├── assets                      # Image assets (textures for walls)
│   ├── wall.xpm                # Wall texture
│   ├── wall_east.xpm           # East wall texture
│   ├── wall_nord.xpm           # North wall texture
│   ├── wall_south.xpm          # South wall texture
│   └── wall_west.xpm           # West wall texture
├── libs                        # MinilibX library
│   └── mlx                     # Library files for MinilibX
├── maps                        # Map files (.cub)
│   ├── map.cub                 # Sample map
│   └── map2.cub                # Another sample map
├── src                         # Source code for Cub3d
│   ├── functions               # Core logic of Cub3d
│   │   ├── cub3d.c             # Main entry point
│   │   ├── file.c              # File handling and map parsing
│   │   ├── image.c             # Image rendering functions
│   │   ├── libft               # Custom string and memory functions
│   │   ├── map.c               # Map parsing logic
│   │   ├── player.c            # Player movement and interaction
│   │   ├── raycasting          # Raycasting functions (drawing, math, movement)
│   │   ├── utils.c             # Utility functions
│   │   └── utils_file.c        # File handling utilities
│   └── headers                 # Header files
│       ├── cub3d.h             # Main header
│       ├── error.h             # Error handling definitions
│       ├── ft_printf.h         # Custom printf
│       ├── get_next_line.h     # Header for GNL
│       └── libft.h             # Header for libft
├── src_bonus                   # Bonus features (optional enhancements)
│   ├── functions               # Bonus functionality
│   └── headers                 # Bonus headers
└── README.md                   # This file
```

---

## Map Format

The project uses `.cub` map files to define the layout of the world. The `.cub` file consists of:

- **Resolution**: Defines the size of the window.
- **Textures**: Paths to the textures for the walls (north, south, east, west).
- **Floor and Ceiling colors**: RGB values for floor and ceiling.
- **Map Layout**: A grid of the world where `1` represents walls and `0` represents empty space.

Example map file (`map.cub`):

```
R 800 600
NO textures/wall_nord.xpm
SO textures/wall_south.xpm
WE textures/wall_west.xpm
EA textures/wall_east.xpm
F 220,220,220
C 0,0,0
1 1 1 1 1 1
1 0 0 0 0 1
1 0 1 1 0 1
1 0 0 0 0 1
1 1 1 1 1 1
```

---

## Libraries

The project utilizes the following libraries:

- **MinilibX**: A lightweight graphics library for window management, input handling, and drawing.
- **libft**: A collection of custom utility functions for string manipulation, memory management, and other common tasks.
- **get_next_line**: A utility for reading input line by line from a file.