//
// Created by bilam on 23/04/2024.
//

#include "Crawler.h"
#include <cstdlib>

Crawler::Crawler(int id, int x, int y, Direction direction, int size)
        : Bug(id, x, y, direction, size) {}


void Crawler::move() {
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
    } else {
        do {
            direction = static_cast<Direction>(rand() % 4 + 1);
        } while (isWayBlocked());
    }
}
