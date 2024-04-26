//
// Created by bilam on 23/04/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

void Board::display() {
    //iterate through columns
    for(int currentY = 0; currentY < 10; currentY++){
        //iterates through rows
        for(int currentX = 0; currentX<10; currentX++){
            std::cout<<board[currentY][currentX] << "  ";
        }
        //will go through the board
        // std::cout<<std::endl;
    }
};


/*void Board::takeInBugs() {
//take in bugs from file
    std::ifstream myFile("bugs.txt");

    //save a breath by checking if it even opens
    if(!myFile){
        std::cerr<<"FAILED TO OPEN: "<< myFile<<std::endl;
        return;
    }
}
 */

void parseLine(const string&strLine, list<Bug*> &bugs){
    stringstream strStream(strLine);

    const char DELIMETER = ';';
    string bug_type;
    getline(strStream, bug_type, DELIMETER);
    string strTemp;

    if(bug_type =="C"){
        getline(strStream, strTemp, DELIMETER);
        int id = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int x = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int y = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int direction = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int size = stoi (strTemp);
        bugs.push_back(new Crawler(id, x, y, direction, size));
    }

    else if(bug_type == "H"){
        getline(strStream, strTemp, DELIMETER);
        int id = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int x = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int y = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int direction = stoi(strTemp);
        getline(strStream, strTemp, DELIMETER);
        int size = stoi (strTemp);
        getline(strStream, strTemp, DELIMETER);
        int hopLength = stoi(strTemp);
        bugs.push_back(new Hopper(id, x, y, direction, size, hopLength));
    }
}
/*
catch (std::invalid_argument const &e) {
    cout << "Invalid argument" << '\n';
}
*/
//add to list of bugs

//print out all bugs in the board
