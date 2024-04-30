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


void Board::InputFileStream() {
    cout << "Attempting to read from a comma-delimited text file." << endl;

    ifstream inFileStream("bugs.txt"); // open file as input file stream (from working directory)

    if (inFileStream.good())  // if file opened successfully, and not empty
    {
        string line;            // create a string object to store a line of text

        while (getline(inFileStream, line))   // read a line until false returned , getline() from <string> library
        {
            parseLine(line, bugsList);  // pass the line of text to have it parsed
        }
        inFileStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

void Board::parseLine(const string& strLine, list<Bug*>& bugs) {
    stringstream strStream(strLine);

    const char DELIMITER = ';';
    string bug_type;
    getline(strStream, bug_type, DELIMITER);
    string strTemp;

    if (bug_type == "C") {
        getline(strStream, strTemp, DELIMITER);
        int id = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int x = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int y = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int direction = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int size = stoi(strTemp);
        bugs.push_back(new Crawler(id, x, y, direction, size));
    }
    else if (bug_type == "H") {
        getline(strStream, strTemp, DELIMITER);
        int id = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int x = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int y = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int direction = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int size = stoi(strTemp);
        getline(strStream, strTemp, DELIMITER);
        int hopLength = stoi(strTemp);
        bugs.push_back(new Hopper(id, x, y, direction, size, hopLength));
    }
}

void Board::display() {
    string dr;
    for (auto bug : bugsList) {
        if(bug->getDirection()==Direction::North){
            dr="North";
        }
        else if(bug->getDirection()==Direction::East){
            dr = "East";
        }
        else if(bug->getDirection()==Direction::South){
            dr = "South";
        }
        else if(bug->getDirection()==Direction::West){
            dr ="West";
        }

        cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << ", Direction: "<<dr<< ", Alive: "<<bug->isAlive() <<endl;
    }
}

void Board::findBug() {
    int m = 0;
    bool found = false;
    cout << "Input a bug id: ";
    cin >> m;
    string dr;
    for (auto bug: bugsList) {
        if (bug->getID() == m) {
            if (bug->getDirection() == Direction::North) {
                dr = "North";
            } else if (bug->getDirection() == Direction::East) {
                dr = "East";
            } else if (bug->getDirection() == Direction::South) {
                dr = "South";
            } else if (bug->getDirection() == Direction::West) {
                dr = "West";
            }
            found = true;
            cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", "
                 << bug->getPosition().second << ")" << ", Direction: " << dr << ", Alive: " << bug->isAlive() << endl;
        }


    }
    if (!found) {
        cout << "Bug " << m << "not found." << endl;
    }

}

void Board::tap() {
    for (auto bug: bugsList) {
        bug->move();
    }

}

void Board::displayLifeHistory(list<Bug*>& bugs){
    for(auto bug : bugsList){

    }
}
//add to list of bugs

//print out all bugs in the board
