//
// Created by bilam on 05/05/2024.
//

#ifndef CA2_MARKETA_BILA_SUPERBUG_H
#define CA2_MARKETA_BILA_SUPERBUG_H


#include "Bug.h"

class SuperBug : public Bug {
public:
    // Constructor
    SuperBug(int id, int x, int y, int direction, int size);

    // Override the move function
    void move();

};

#endif //CA2_MARKETA_BILA_SUPERBUG_H
