//
// Created by bilam on 23/04/2024.
//

#include "Bug.h"

//constructor
bool Bug::isWayBlocked() const {
    int x = position.first;
    int y = position.second;
    // against top edge
    return (y == 0 && direction == Direction::North) ||
           // against right edge
           (x == 9 && direction == Direction::East) ||
           // against bottom edge
           (y == 9 && direction == Direction::South) ||
           // against left edge
           (x == 0 && direction == Direction::West);
}


// Getters
int Bug::getID() const { return id; }
pair<int, int> Bug::getPosition() const { return position; }
Direction Bug::getDirection() const { return direction; }
int Bug::getSize() const { return size; }
bool Bug::isAlive() const { return alive; }
list<pair<int, int>> Bug::getPath() const { return path; }

// Setters
void Bug::setPosition(int x, int y) { position.first = x; position.second = y; }
void Bug::setDirection(Direction _direction) { direction = _direction; }
void Bug::setSize(int _size) { size = _size; }
void Bug::setAlive(bool status) { alive = status; }
void Bug::addToPath(int x, int y) { path.push_back(make_pair(x, y)); }



