//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_BUG_H
#define CA2_MARKETA_BILA_BUG_H

#include <iostream>
#include <utility>
#include <list>

using namespace std;

enum class Direction {North = 1, East, South, West};

//all the bug variables
class Bug {
protected:
    Bug(int id, int x, int y, Direction direction, int size);

    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    // Getters
    int getID() const;
    pair<int, int> getPosition() const;
    Direction getDirection() const;
    int getSize() const;
    bool isAlive() const;
    list<pair<int, int>> getPath() const;

    // Setters
    void setPosition(int x, int y);
    void setDirection(Direction _direction);
    void setSize(int _size);
    void setAlive(bool status);
    void addToPath(int x, int y);

    virtual void move() = 0;
    bool isWayBlocked() const;
};

// Constructor definition
    Bug::Bug(int id, int x, int y, Direction direction, int size)
        : id(id), position(make_pair(x, y)), direction(direction), size(size), alive(true) {}


bool Bug::isWayBlocked() const {
    int x = position.first;
    int y = position.second;
    return (y == 0 && direction == Direction::North) ||   // against top edge
           (x == 9 && direction == Direction::East) ||    // against right edge
           (y == 9 && direction == Direction::South) ||   // against bottom edge
           (x == 0 && direction == Direction::West);      // against left edge
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

#endif //CA2_MARKETA_BILA_BUG_H
