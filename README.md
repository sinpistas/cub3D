# cub3D

*This project has been created as part of the 42 curriculum by ancanale, apestana.*

## Description

**cub3D** is a 3D graphical representation of a maze from a first-person perspective, inspired by the iconic Wolfenstein 3D game. The project implements a raycasting engine using the miniLibX graphics library to render textured walls, floors, and ceilings in real-time.

The main goal is to understand and implement the fundamental principles of raycasting, a rendering technique that creates a 3D perspective in a 2D map. The project involves:
- Parsing and validating map configuration files
- Implementing ray-wall intersection calculations (DDA algorithm)
- Rendering textured walls with proper perspective
- Handling player movement and camera rotation
- Managing window events and user input

## Instructions

### Prerequisites
- Linux operating system (tested on Ubuntu)
- X11 development libraries
- C compiler (gcc/clang)
- Make

### Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd cub3d
```

2. Install required dependencies:
```bash
sudo apt-get update
sudo apt-get install -y libx11-dev libxext-dev libbsd-dev
```

3. Compile the project:
```bash
make
```

### Usage

Run the program with a map file:
```bash
./cub3D maps/good/huge_maze.cub
```

Available make commands:
- `make` - Compile the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Full recompilation
- `make bonus` - Compile with bonus features (if implemented)

### Controls

- **W** - Move forward
- **S** - Move backward
- **A** - Strafe left
- **D** - Strafe right
- **←** - Rotate camera left
- **→** - Rotate camera right
- **ESC** - Exit program

### Map Format

Maps must have a `.cub` extension and contain:
- Texture paths for each wall direction (NO, SO, EA, WE)
- Floor color (F R,G,B)
- Ceiling color (C R,G,B)
- Map layout using: `0` (empty space), `1` (wall), `N/S/E/W` (player start position)

Example:
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
101N01
111111
```

### Testing

Test the parser with provided test maps:
```bash
# Valid maps (should all pass)
bash good_test.sh

# Invalid maps (should all fail)
bash bad_test.sh

# Memory leak testing
bash valgrind_test.sh
```

Test mode (parsing only, no GUI):
```bash
./cub3D --test maps/good/minimal.cub
```

## Features

- ✅ Complete raycasting engine with DDA algorithm
- ✅ Textured walls for all 4 directions
- ✅ Smooth player movement with diagonal support
- ✅ Camera rotation
- ✅ Floor and ceiling colors
- ✅ Collision detection
- ✅ Comprehensive map parser with validation
- ✅ Memory leak free (valgrind verified)
- ✅ Window management (resizing, closing)

## Resources

### Documentation
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive raycasting guide
- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library reference
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d) - Original game implementation
- [Ray-Casting Tutorial For Game Development](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - F. Permadi's tutorial

### Technical References
- X11 Programming Manual - For understanding graphics display
- DDA Algorithm - Digital Differential Analysis for line drawing
- Linear Algebra - Vector operations for 3D transformations

### AI Usage

AI assistance (GitHub Copilot/ChatGPT) was used for:
- **Initial project structure setup** - Makefile organization, header file structure
- **Code documentation** - Adding comments and explaining complex algorithms
- **Debugging assistance** - Identifying logic errors in raycasting calculations
- **Code optimization** - Suggesting performance improvements
- **Test script creation** - Automating parser validation tests
- **Memory management review** - Ensuring proper allocation/deallocation

**Core implementation** was done manually:
- Raycasting algorithm (DDA, wall distance calculations)
- Texture mapping and rendering logic
- Map parser and validation
- Event handling and game loop
- Camera movement and rotation