//
// Created by bilam on 23/04/2024.
//

#include "Bug.h"

Bug::Bug(int id, const std::pair<int, int> &position, int direction, int size) : id(id), position(position),
                                                                                 direction(direction), size(size), path() {}
