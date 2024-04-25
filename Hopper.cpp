//
// Created by bilam on 23/04/2024.
//

#include "Hopper.h"

//put move code here
void Hopper::move() {}

Hopper::Hopper(int id, const std::pair<int, int> &position, int direction, int size, int hopLength) : Bug(id, position, direction, size), hopLength(hopLength)
{}
