Rubik's Cube Solver
Overview

The program implements the human method to solve a scrambled Rubik's Cube, providing step-by-step instructions to complete each stage of the solution. The program automatically generates a scramble and applies it to the cube. Then it solves the cube based on the steps below.
    Solve the cross.
    Place the first-layer corners.
    Solve the second-layer edges.
    Create the last-layer cross.
    Finish solving the last layer.

Getting Started
Prerequisites

    C++ Compiler: Make sure you have a modern C++ compiler (e.g., g++, clang).
    SFML (optional): There are two versions. One uses SFML and the other does not. The SFML version just allows you to better visualize the state of the cube after each step is solved. The non-SFML version is primarily used for benchmarking.

Build the project:

    You should just be able to navigate into either the RCS folder or the RCS_SFML folder and run "make". Keep in mind that the LIB_PATH and the INC_PATH defined in the makefile are specific to my system so you will likely have to change those paths to where SFML is installed on your local machine if you want to use the SFML version. 
    After you have made the executable you should just be able to run it. "./RCS"

Usage

    Follow the program prompts to input the scrambled state of the cube. Each side is represented by six characters corresponding to its colors (W, Y, R, O, B, G).
    The program will output the sequence of moves required to solve the cube step by step.

Project Structure

    main.cpp: Entry point of the program.
    Cube.cpp: Implementation of the solver algorithms.
    Cube.h: Header file containing class and function declarations.
    arial.ttf: The font used by the SFML version.
    Makefile: File that builds the executable.
    solution.txt: Text file that is written to only if there was an error where the cube could not be solved. Most used for debugging purposes.

License

    This project is licensed under the MIT License.
