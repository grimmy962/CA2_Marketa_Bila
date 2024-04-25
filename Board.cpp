//
// Created by bilam on 23/04/2024.
//
#include <iostream>
#include <fstream>
#include "Board.h"
using namespace std;

void Board::display() {
    //iterate through columns
    for(int currentY = 0; currentY < 10; currentY++){
        //iterates through rows
        for(int currentX = 0; currentX<10; currentX++){
            std::cout<<board[currentY][currentX] << "  ";
        }
        //will go through the board
        std::cout<<std::endl;
    }
};

void Board::takeInBugs() {
//take in bugs from file
    std::string myBugs;
    std::ifstream MyReadFile("bugs.txt");
    while (getline(MyReadFile, myBugs)) {
        cout << myBugs;
    }
    MyReadFile.close();
}
//add to list of bugs

//print out all bugs in the board
