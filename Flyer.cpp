//
// Created by bilam on 05/05/2024.
//

#include "Flyer.h"

Flyer::Flyer(int id, int x, int y, int direction, int size, int flyLength) :
        Bug(id, x, y, direction, size), flyLength(flyLength){}

void Flyer:: move(){
    if (!isWayBlocked()) {
        //moves by the specified hop length in it's current direction
        //if it hits the edge and can't move in the current direction, it will change it's direction randomly until it can move again
        //and it records the new position in the hopper's path history
        switch (direction) {
            case Direction::North:
                for (int i = 0; flyLength > i; ++i) {
                    if (position.second > 0) {
                        position.second = position.second - 3;
                    }
                }
                break;
            case Direction::East:
                for (int i = 0; flyLength > i; ++i) {
                    if (position.first < 9) {
                        position.first = position.first + 3;
                    }
                }
                break;
            case Direction::South:
                for (int i = 0; flyLength > i; ++i) {
                    if (position.second < 9) {
                        position.second = position.second + 3;
                    }
                }
                break;
            case Direction::West:
                for (int i = 0; flyLength > i; ++i) {
                    if (position.first > 0) {
                        position.first = position.first - 3;
                    }
                }
                break;
                addToPath(position.first, position.second);
        }
    }
    else {
        do {
            direction = static_cast<Direction>(rand() % 4 + 1);
        }
        while (isWayBlocked());
    }
}

