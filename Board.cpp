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
#include "Flyer.h"
#include <SFML/Graphics.hpp>
#include <vector>

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
    else if (bug_type == "F") {
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
        int flyLength = stoi(strTemp);
        bugs.push_back(new Flyer(id, x, y, direction, size, flyLength));
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

        cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << ", Direction: "<<dr<< ", Size: "<<bug->getSize()<<", Alive: "<<bug->isAlive() <<endl;
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
    eat();

}

//go through each bug
void Board::displayLifeHistory(){
    for(const auto& bug : bugsList) {
        //get their information and determine which bug type it is
        cout << "Bug ID: " << bug->getID() << "Type: " << (dynamic_cast<Crawler *>(bug) ? "Hopper" : "Flyer")
             << " Path: ";
        //add another for loop to iterate through every position in the bug's path
        for (const auto &position: bug->getPath()) {
            cout << "(" << position.first << "," << position.second << "), ";
        }
        //print the bug's status
        cout << (bug->isAlive() ? "Alive!\n" : "Dead\n");
    }
}

//inspired by: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
void Board::writeLifeHistory(){
    //get current date and time
    time_t now = time(0);
    char dateTime[80];
    //format the date and time
    strftime(dateTime, 80, "%Y-%m-%d_%H-%M-%S", localtime(&now));

    //create new file called bugs_life_history_date_time_out
    string filename = "bugs_life_history_" + string(dateTime) + ".out";
    //open the file
    ofstream outFile(filename);

    //and write in to the file
    //go through the bugs and get their information (same as in displayLifeHistory)
    for (const auto& bug : bugsList) {
        outFile << "Bug ID: " << bug->getID() << " Type: " << (dynamic_cast<Crawler*>(bug) ? "Hopper" : "Flyer")
                << " Path: ";
        for (const auto& pos : bug->getPath()) {
            outFile << "(" << pos.first << "," << pos.second << "), ";
        }
        outFile << (bug->isAlive() ? "Alive!\n" : "Dead\n");
    }

    //close the file
    outFile.close();
    //inform the user that it's complete
    cout << "Life history of all bugs has been written to: " << filename << endl;
}

//print out the cells 10x10
void Board:: displayAllCells() {
    bool empty;
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            bool empty = true;
            string dr;
            //display them
            cout << "\n(" << x << "," << y << "): ";
            //if cell empty(no bug) print out empty
            for (const auto &bug: bugsList) {
                if (bug->getPosition().first == x & bug->getPosition().second == y) {
                    if (bug->getDirection() == Direction::North) {
                        dr = "North";
                    } else if (bug->getDirection() == Direction::East) {
                        dr = "East";
                    } else if (bug->getDirection() == Direction::South) {
                        dr = "South";
                    } else if (bug->getDirection() == Direction::West) {
                        dr = "West";
                    }
                    cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << ", Direction: "<<dr<< ", Alive: "<<bug->isAlive();
                    empty = false;
                }
            }
            if(empty){
                cout<<"Empty";
            }
        }
    }
}

void Board::eat(){
    std::list<Bug *> cellBugs;
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            cellBugs.clear();
            for (const auto& bug : bugsList) {
                if(bug->getPosition().first==x && bug->getPosition().second == y && bug->isAlive()){
                    cellBugs.push_back(bug);
                }
            }
            if(cellBugs.size()>1){
                //sort the bugs that are in the same cell based on their size
                cellBugs.sort([](Bug* a, Bug* b){
                    return a->getSize() > b->getSize();
                });

                //the bigger bug wins
                auto winner = cellBugs.front();
                //and is removed from the list
                cellBugs.pop_front();

                //mark the other as dead and get their size
                int totalEatenSize = 0;
                for(auto bug: cellBugs){
                    //determine how much the winner will eat
                    bug->setAlive(false);
                    totalEatenSize += bug ->getSize();
                }

                //increase the winner's size by the defeated bugs size
                winner -> setSize(winner->getSize() + totalEatenSize);
                //remove the defeated bug from the cell
                cellBugs.clear();
            }


        }
    }
}

void Board::runSimulation(){
    std::ofstream outFile("simulation.txt");
    int taps = 0;

    while(!isGameOver()){
        taps++;
        cout<<"Round: "<<taps<<endl;

        tap();
        display();
        sleep(1);
        cout<<endl;
    }
}

bool Board::isGameOver(){
    int bugsAlive=0;
    for (const auto& bug : bugsList) {
        if(bug->isAlive()){
            bugsAlive++;
        }
    }
    if(bugsAlive ==1){
        return true;
    }
    return false;
    }

void Board::sfml()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape character(2.5);
    character.setPosition(200,390);
    character.setFillColor(sf::Color::Red);
    vector<sf::RectangleShape> squares;
    for(int x = 0; x < 80;x ++)
    {
        for(int y=0; y<80;y++)
        {
            sf::RectangleShape cell(sf::Vector2f(5,5));
            cell.setPosition(x*5, y*5);
            //cell.setOutlineThickness(1);
            //cell.setOutlineColor(sf::Color::Black);
            squares.push_back(cell);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyReleased)
            {
                int x = character.getPosition().x;
                int y = character.getPosition().y;
                if(event.key.code == sf::Keyboard::Up)
                {
                    if(y> 0)
                        character.setPosition(x, y-5);
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    if(y<395 )
                        character.setPosition(x, y+5);
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    if(x> 0)
                        character.setPosition(x-5, y);
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    if(x<395)
                        character.setPosition(x+5, y);
                }
                if(event.key.code == sf::Keyboard::Space)
                {
                    for(sf::RectangleShape &sh:squares)
                    {
                        if(x == sh.getPosition().x
                           && y ==sh.getPosition().y )
                        {
                            sh.setFillColor(sf::Color::Green);
                        }
                    }
                }


            }
            if(event.type == sf::Event::MouseButtonReleased)
            {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                for(sf::RectangleShape &sh:squares)
                {
                    if(x >= sh.getPosition().x&&x < sh.getPosition().x+10
                       && y >=sh.getPosition().y&&y < sh.getPosition().y+10 )
                    {
                        sh.setFillColor(sf::Color::Green);
                    }
                }
            }

        }


        window.clear(sf::Color::White);
        for(sf::RectangleShape sh:squares)
        {
            window.draw(sh);
        }
        window.draw(character);
        window.display();

    }
}


