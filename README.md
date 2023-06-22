Game of Life 🎮
Welcome to the Game of Life repository! 🌟 This project is an implementation of Conway's Game of Life using C++ and the SFML library.

What is the Game of Life?
The Game of Life, devised by the mathematician John Horton Conway in 1970, is a cellular automaton. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. The game takes place on an infinite grid of square cells, each of which can be in one of two states: alive or dead. The state of each cell evolves over time according to a set of rules.

Rules of the Game 📖
The game follows these simple rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

How to Play 🎯
Setting Up: Initially, you will need to provide an initial configuration of live cells on the grid. This can be done by modifying the source code or by loading predefined configurations.
Running the Simulation: Once the initial configuration is set, run the program. The cells will evolve following the rules of the game.
Observe and Enjoy: Sit back and watch the mesmerizing patterns that emerge as the game progresses. You can pause or reset the simulation at any time.
Installation and Dependencies 🛠️
To run the Game of Life, you will need to have the following dependencies installed:

C++ Compiler (supporting C++11 or later)
SFML Library
Follow these steps to get started:

Clone this repository to your local machine.
Ensure that the SFML library is correctly installed.
Build the project using your preferred C++ compiler.
Run the executable generated.
