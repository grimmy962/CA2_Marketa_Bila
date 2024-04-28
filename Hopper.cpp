//
// Created by bilam on 23/04/2024.
//

#include "Hopper.h"

Hopper::Hopper(int id, int x, int y, Direction direction, int size, int hopLength)
        : Bug(id, x, y, direction, size), hopLength(hopLength) {}

//put move code here
void Hopper::move() {
    //so if the hopper is not blocked
    if (!isWayBlocked()) {
        //moves by the specified hop length in it's current direction
        //if it hits the edge and can't move in the current direction, it will change it's direction randomly until it can move again
        //and it records the new position in the hopper's path history
        switch (direction) {
            case Direction::North:
                while (hopLength-- && position.second > 0)
                    position.second--;
                break;
            case Direction::East:
                while (hopLength-- && position.first < 9)
                    position.first++;
                break;
            case Direction::South:
                while (hopLength-- && position.second < 9)
                    position.second++;
                break;
            case Direction::West:
                while (hopLength-- && position.first > 0)
                    position.first--;
                break;
        }
        addToPath(position.first, position.second);
    } else {
        do {
            direction = static_cast<Direction>(rand() % 4 + 1);
           }
        while (isWayBlocked());
    }
}

