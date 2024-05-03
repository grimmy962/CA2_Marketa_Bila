#include <iostream>
#include "Board.h"
using namespace std;

int main() {
    int menu = 0;
    Board board;
    while(menu!=8){
        cout<<"1. Initialize Bug Board (load data from file)\n"
              "2. Display all Bugs\n"
              "3. Find a Bug (given an id)\n"
              "4. Tap the Bug Board (causes move all, then fight/eat)\n"
              "5. Display Life History of all Bugs (path taken)\n"
              "6. Display all Cells listing their Bugs\n"
              "7. Run simulation (generates a Tap every second)\n"
              "8. Exit (write Life History of all Bugs to file)\n"<<endl;
        cin>>menu;

        switch (menu) {
            case 1:
                board.InputFileStream();
                break;
            case 2:
                board.display();
                break;
            case 3:
                board.findBug();
                break;
            case 4:
                board.tap();
                break;
            case 5:
                board.displayLifeHistory();
                break;
            case 6:
                board.writeLifeHistory();
                break;
            case 7:
                board.displayAllCells();
                break;
            case 8:
                // Case 8 is empty
                break;
            default:
                // Default case is empty
                break;
        }
    }

}

//print menu
// or menu logic