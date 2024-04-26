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

void parseLine(const string& strLine, list<Bug*>& bugs);

void DemoInputFileStream(list<Bug*>& bugs) {
    cout << "Attempting to read from a comma-delimited text file." << endl;

    ifstream inFileStream("bugs.txt"); // open file as input file stream (from working directory)

    if (inFileStream.good())  // if file opened successfully, and not empty
    {
        string line;            // create a string object to store a line of text

        while (getline(inFileStream, line))   // read a line until false returned , getline() from <string> library
        {
            parseLine(line, bugs);  // pass the line of text to have it parsed
        }
        inFileStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

void parseLine(const string& strLine, list<Bug*>& bugs) {
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

void printBugs(list<Bug*>& bugs) {
    for (auto bug : bugs) {
        cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getX() << ", " << bug->getY() << ")" << endl;
    }
}
//add to list of bugs

//print out all bugs in the board
