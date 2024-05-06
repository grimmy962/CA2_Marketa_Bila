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

    // open file as input file stream (from working directory)
    ifstream inFileStream("bugs.txt");

    // if file opened successfully, and not empty
    if (inFileStream.good())
    {
        // create a string object to store a line of text
        string line;

        // read a line until false returned , getline() from <string> library
        while (getline(inFileStream, line))
        {
            // pass the line of text to have it parsed
            parseLine(line, bugsList);
        }
        //close the file
        inFileStream.close();
    }
    else
        cout << "Unable to open file, or file is empty.";
}

//function to create a different instances of bugs
void Board::parseLine(const string& strLine, list<Bug*>& bugs) {
    //stream extracts data from the string
    stringstream strStream(strLine);

    //define new variables, delimiter to separate the fields
    const char DELIMITER = ';';
    string bug_type;
    //getline will convert them into integeres and some other parameteres specific to bug type
    getline(strStream, bug_type, DELIMITER);
    //temporary container to hold the substring as we are iterating through the info
    string strTemp;

    //creates different bug types and get their information
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
        //adds the bug into the bugs list using push_back
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

//function responsible for displaying all the bugs
void Board::display() {
    //string variable to hold the direction
    string dr;
    //using a for loop to go through the list of bugs
    for (auto bug : bugsList) {
        //and gets the directiong of the bug and displays him
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

        //also includes other relevant information
        cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", " << bug->getPosition().second << ")" << ", Direction: "<<dr<< ", Size: "<<bug->getSize()<<", Alive: "<<bug->isAlive() <<endl;
    }
}

//function to find a bug based on their id
void Board::findBug() {
    //for storing the user input
    int m = 0;
    //bool to find ot if the bug is found
    bool found = false;
    //ask user fot id
    cout << "Input a bug id: ";
    //store the answer
    cin >> m;
    //variable for the direction
    string dr;
    //use for loop to go through the code
    for (auto bug: bugsList) {
        //if the bug id equals with the user input, gets the direction
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
            //also tells other information
            cout << "Bug ID: " << bug->getID() << ", Position: (" << bug->getPosition().first << ", "
                 << bug->getPosition().second << ")" << ", Direction: " << dr << ", Alive: " << bug->isAlive() << endl;
        }


    }
    //if not found displays this message
    if (!found) {
        cout << "Bug " << m << "not found." << endl;
    }

}

//function to make the bugs move every tap(everytime we tap 4)
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
        cout << "Bug ID: " << bug->getID() << " Type: ";
        //using the dynamic_cast(used in polymorphic class hierarchies)
        //so it converts the pointer bug into a pointer of type crawler
        if (dynamic_cast<Crawler *>(bug)) {
            cout << "Crawler";
        } else if (dynamic_cast<Hopper *>(bug)) {
            cout << "Hopper";
        } else if (dynamic_cast<Flyer *>(bug)) {
            cout << "Flyer";
        } else {
            cout << "Unknown"; // Handle the case where the bug is not of any known type
        }
        cout << " Path: ";
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
    //format the date and time into a string
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
    //bool to see if there is something in the cell
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

//eat function to make two bugs in the same cell fight each other and the smaller one will be eaten
void Board::eat(){
    //list of the bags in the same cell
    std::list<Bug *> cellBugs;
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            //before checking for bugs in the current cell it will clear the cellBugs list
            cellBugs.clear();
            //goes through the bug list and get the bugs that are in the same cell and are alive, they will get into the cellBugs
            for (const auto& bug : bugsList) {
                if(bug->getPosition().first==x && bug->getPosition().second == y && bug->isAlive()){
                    cellBugs.push_back(bug);
                }
            }
            //if there is more than 1 bug in the same cell the fight begins
            if(cellBugs.size()>1){
                //it sorts the bugs that are in the same cell based on their size
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
                //clear the list since all bugs in the cell have been eaten/removed
                cellBugs.clear();
            }


        }
    }
}

//runs the game
void Board::runSimulation(){
    //opens file to write down the simulation results
    std::ofstream outFile("simulation.txt");
    //this will count the number of taps
    int taps = 0;

    //while loop that continues until the game is over
    while(!isGameOver()){
        //counts the taps and displays it as rounds
        taps++;
        cout<<"Round: "<<taps<<endl;

        //calls the tap action to, then display function to display the current state
        tap();
        display();
        //pauses the simulation for a second for the player to read the results
        sleep(1);
        cout<<endl;
    }
}

//function to determine whether the class is over
bool Board::isGameOver(){
    //counts alive bugs
    int bugsAlive=0;
    //goes through all the bugs and counts them
    for (const auto& bug : bugsList) {
        if(bug->isAlive()){
            bugsAlive++;
        }
    }
    //if there is one bug alive it means game over
    if(bugsAlive ==1){
        return true;
    }
    return false;
    }

    //taken from: https://github.com/delboy8080/SFML_Sample2
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


