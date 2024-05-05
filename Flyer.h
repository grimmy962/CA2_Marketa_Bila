//
// Created by bilam on 05/05/2024.
//

#ifndef CA2_MARKETA_BILA_FLYER_H
#define CA2_MARKETA_BILA_FLYER_H


#include "Bug.h"

class Flyer : public Bug {
protected:
    int flyLength;

public:
    Flyer(int id, int x, int y, int direction, int size, int flyLength);

    void move() override;
};

#endif //CA2_MARKETA_BILA_FLYER_H
