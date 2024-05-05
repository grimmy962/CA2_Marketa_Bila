//
// Created by bilam on 05/05/2024.
//

#include "SuperBug.h"

SuperBug::SuperBug(int id, int x, int y, int direction, int size) :
         Bug(id, x, y, direction, size){};

void SuperBug::move() {
    pair<int, int> pos = getPosition();

    if (!isWayBlocked()) {
        switch (direction) {
            case Direction::North:
                position.second--;
                break;
            case Direction::East:
                position.first++;
                break;
            case Direction::South:
                position.second++;
                break;
            case Direction::West:
                position.first--;
                break;
        }
        addToPath(position.first, position.second);
    }
}