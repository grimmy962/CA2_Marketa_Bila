//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_HOPPER_H
#define CA2_MARKETA_BILA_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
protected:
    int hopLength;
    virtual void move();

public:
    Hopper(int id, int x, int y, int direction, int size, int hopLength);
};


#endif //CA2_MARKETA_BILA_HOPPER_H
