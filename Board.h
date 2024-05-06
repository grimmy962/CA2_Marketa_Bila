//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_BOARD_H
#define CA2_MARKETA_BILA_BOARD_H

#include <iostream>
#include "Bug.h"
#include <unistd.h>


class Board {
private:
    //making a 10x10 board
    char board[10][10];

protected:
    //list of bugs
    std::list<Bug *> bugsList;

public:
    Board() {
        //1)
        //for loop to make the board
        for (int currentY = 0; currentY < 10; currentY++) {
            for (int currentX = 0; currentX < 10; currentX++) {
                board[currentY][currentX] = '-';
            }
        }
    };

    void display();

    void InputFileStream();

    void parseLine(const string& strLine, list<Bug*>& bugs);

    void findBug();

    void tap();

    void displayLifeHistory();

    void writeLifeHistory();

    void displayAllCells();

    void eat();

    void runSimulation();

    bool isGameOver();

    void sfml();
};

#endif //CA2_MARKETA_BILA_BOARD_H