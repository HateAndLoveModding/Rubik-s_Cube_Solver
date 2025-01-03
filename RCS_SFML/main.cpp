#include "Cube.h"
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main() {
    Cube theCube;
    cout << "Welcome to the program that will solve a Rubik's Cube using the beginner method for humans." << endl;
    cout << "This version will display the cube using SFML. It will only solve the cube once."
    sf::RenderWindow window(sf::VideoMode(1900, 800), "Rubik's Cube Solver");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::White);
    text.setPosition(20, 540);
    cout << "Press the space bar to perform the next step. Once the cube is solved, press the space bar one more time to exit the program." << endl;
    theCube.scrambleCube();
    bool proceedToNextStep = false;
    bool crossSolved = false, cornersSolved = false, middleLayerSolved = false;
    bool lastLayerCrossSolved = false, lastLayerCornersSolved = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                proceedToNextStep = true;
            }
        }
        if (proceedToNextStep) {
            if (!crossSolved) {
                theCube.solveCross();
                crossSolved = true;
            } else if (!cornersSolved) {
                theCube.solveCorners();
                cornersSolved = true;
            } else if (!middleLayerSolved) {
                theCube.solveMiddleLayerEdges();
                middleLayerSolved = true;
            } else if (!lastLayerCrossSolved) {
                theCube.solveLastLayerCross();
                lastLayerCrossSolved = true;
            } else if (!lastLayerCornersSolved) {
                theCube.solveLastLayerCorners();
                lastLayerCornersSolved = true;
            } else {
                std::ofstream fout("solution.txt");
                if (!fout) {
                    std::cerr << "Error opening solution file.\n";
                    return -1;
                }
                fout << theCube.getMoves();
                break;
            }
            proceedToNextStep = false;
        }

        text.setString(theCube.getMoves());
        window.clear();
        theCube.displayRubiksCube(window);
        window.draw(text);
        window.display();
    }
    return 0;
}
