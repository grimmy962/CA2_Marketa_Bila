//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_HOPPER_H
#define CA2_MARKETA_BILA_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
protected:
    int hopLength;

public:
    Hopper(int id, int x, int y, Direction direction, int size, int hopLength);

    void move() override;
};

#endif //CA2_MARKETA_BILA_HOPPER_H
