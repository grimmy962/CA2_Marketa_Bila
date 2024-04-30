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
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<pair<int, int>> path;

public:
    // Constructor
    Bug(int id, int x, int y, int directionIn, int size)
            : id(id), position(std::make_pair(x, y)), direction(static_cast<Direction>(directionIn)), size(size), alive(true) {
    };

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

    // Destructor (virtual to allow derived classes to override)
    virtual ~Bug() {}
};


#endif //CA2_MARKETA_BILA_BUG_H
