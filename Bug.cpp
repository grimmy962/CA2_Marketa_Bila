//
// Created by bilam on 23/04/2024.
//

#include "Bug.h"
#include <iostream>
#include <utility>
#include <list>
#include <cstdlib>


//constructor
Bug::Bug(int id, int x, int y, Direction direction, int size)
{
    this->id = id;
    this->position.first = x;
    this->position.second = y;
    this->direction = direction;
    this->size = size;
    this->alive = true;

}





