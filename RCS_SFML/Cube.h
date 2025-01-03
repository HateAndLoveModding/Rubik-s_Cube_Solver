#ifndef CUBE_H
#define CUBE_H
#include <string>
#include <SFML/Graphics.hpp>

class Cube {
    private:
    char* whiteSide;
    char* greenSide;
    char* redSide;
    char* orangeSide;
    char* blueSide;
    char* yellowSide;
    std::string _moves;

    /**
     * @brief Performs the algorithm to rotate the last layer corners to the correct position
     * 
     */
    void rotateLastLayerCorners();

    /**
     * @brief Checks is a corner in the last layer is in the correct position
     * 
     */
    void isCornerCorrect(int&);

    /**
     * @brief Rotates the corners in the last layer to the correct position
     * 
     */
    void lastLayerCornerHelper(int&);

    /**
     * @brief Performs the algorithm that rotates corners into the solved state
     * 
     */
    void orientCornersAlg();

    /**
     * @brief Determines how many last layer corners are completely solved and returns an integer of the position of one solved corner
     * 
     * @return int 
     */
    int orientCornerHelper(int&);

    /**
     * @brief Performs the algoritm to solve the yellow cross
     * 
     */
    void lastLayerCrossAlg();

    /**
     * @brief Rotates three last layer edge pieces clockwise
     * 
     */
    void orientCrossClockwise();

    /**
     * @brief Rotates three last layer edge pieces counterclockwise 
     * 
     */
    void orientCrossCounterclockwise();

    /**
     * @brief Rotates the top two layers so that an unsolved edge piece is in the buffer position
     * 
     * @return int 
     */
    int middleLayerHelper();

    /**
     * @brief Reverses the moves performed by middleLayerHelper to reorient the cube so that green is facing forward
     * 
     */
    void resetMiddleLayer(int);

    /**
     * @brief Performs the algorithm to insert an edge piece to the left
     * 
     */
    void middleLeft();

    /**
     * @brief Performs the algorithm to insert an edge piece to the right
     * 
     */
    void middleRight();

    /**
     * @brief Turns the white side clockwise until there is not a white piece facing up in the buffer position
     * 
     */
    void resetAUF();

    /**
     * @brief Rotates array positions 0,2,6,8 clockwise and positions 1,3,5,7 clockwise
     * 
     * @param arr 
     */
    void shiftArrayClockwise(char*);

    /**
     * @brief Rotates array positions 0,2,6,8, counterclockwise and positions 1,3,5,7 counterclockwise
     * 
     */
    void shiftArrayCounterclockwise(char*);

    /**
     * @brief Calls the overloaded function turnSideClockwise with the input being index 4 of the array
     * 
     * @return std::string 
     */
    std::string turnSideClockwise(char*);

    /**
     * @brief Performs the array manipulation to reflect a clockwise turn on a Rubik's cube
     * 
     * @return std::string 
     */
    std::string turnSideClockwise(char);

    /**
     * @brief Calls the overloaded function shiftArrayCounterclockwise with the input being index 4 of the array
     * 
     * @return std::string 
     */
    std::string turnSideCounterclockwise(char*);

    /**
     * @brief Performs the array manipulation to reflect a counterclockwise turn on a Rubik's cube
     * 
     * @return std::string 
     */
    std::string turnSideCounterclockwise(char);

    /**
     * @brief Performs an algorithm to solve a white edge piece
     * 
     */
    void solveWhiteLayerCrossPieces(char*, char*);

    public:

    void resetCube();
    void resetMoves();

    /**
     * @brief Creates 6 arrays each representing a side of a solved Rubik's cube
     * 
     */
    Cube();

    /**
     * @brief Randomly performs 20 moves to scramble the cube
     * 
     */
    void scrambleCube();

    /**
     * @brief Returns a string of all moves that have been performed on the cube
     * 
     * @return std::string 
     */
    std::string getMoves() const;

    /**
     * @brief Solves the white cross 
     * 
     */
    void solveCross();

    /**
     * @brief Solves the white corner piece on the first layer
     * 
     */
    void solveCorners();

    /**
     * @brief Displays the current state of the Rubik's cube using SFML
     * 
     * @param window 
     */
    void displayRubiksCube(sf::RenderWindow& window) const;

    /**
     * @brief Solves the middle layer edge pieces
     * 
     */
    void solveMiddleLayerEdges();

    /**
     * @brief Solves the yellow cross
     * 
     */
    void solveLastLayerCross();

    /**
     * @brief Solves the corners on the last layer
     * 
     */
    void solveLastLayerCorners();

    bool isCubeSolved();
};

#endif