//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_BUG_H
#define CA2_MARKETA_BILA_BUG_H


#include <utility>
#include <list>

class Bug {
protected:
int id;
std::pair<int, int> position;
int direction;
int size;
bool live;
std::list<std::pair<int, int>> path;
virtual void move();
bool isWayBlocked;

public:
    Bug(int id, const std::pair<int, int> &position, int direction, int size);
};


#endif //CA2_MARKETA_BILA_BUG_H
