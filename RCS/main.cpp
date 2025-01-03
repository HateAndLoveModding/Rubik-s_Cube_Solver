#include "Cube.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
using namespace std;

int main() {
    Cube theCube;
    int numberOfSolves;
    cout << "Welcome to the program that will solve a Rubik's Cube using the beginner method for humans." << endl;
    cout << "Press 1 to solve the cube once and print result. Press 2 to benchmark." << endl;
    cin >> numberOfSolves;
    if(numberOfSolves==2) {
        int n=0, final;
        cout << "How many solves do you want to do? I can solve roughly 50K cubes per second." << endl;
        cin >> final;
        auto start = std::chrono::high_resolution_clock::now();
        theCube.scrambleCube();
        while(n<final) {
            n++;
            theCube.scrambleCube();
            theCube.solveCross();
            theCube.solveCorners();
            theCube.solveMiddleLayerEdges();
            theCube.solveLastLayerCross();
            theCube.solveLastLayerCorners();
            if(!theCube.isCubeSolved()) {
                ofstream fout("solution.txt");
                if(!fout) {return -1;}
                fout << theCube.getMoves();
                cout << "All tests were not passed." << endl;
                break;
            }
            theCube.resetCube();
            theCube.resetMoves();
            cout << n << endl;
        }
        auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count();
        cout << "Execution time for " << final << " solves is: " <<  duration << " microseconds." << endl;
        cout << "Average execuation time is: " << duration/final << endl;
    } else if(numberOfSolves==1) {
        theCube.scrambleCube();
        theCube.printCube();
        theCube.solveCross();
        theCube.printCube();
        theCube.solveCorners();
        theCube.printCube();
        theCube.solveMiddleLayerEdges();
        theCube.printCube();
        theCube.solveLastLayerCross();
        theCube.printCube();
        theCube.solveLastLayerCorners();
        theCube.printCube();
        if(!theCube.isCubeSolved()) {
            ofstream fout("solution.txt");
            if(!fout) {return -1;}
            fout << theCube.getMoves();
            cout << "Error. Cube should be solved but it is not." << endl;
        }
    }
    return 1;
}