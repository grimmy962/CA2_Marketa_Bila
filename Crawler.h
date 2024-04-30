//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_CRAWLER_H
#define CA2_MARKETA_BILA_CRAWLER_H


#include "Bug.h"

class Crawler: public Bug {

public:
    // Constructor
    Crawler(int id, int x, int y, int direction, int size);

    // Override the move function
    void move() override;
};




#endif //CA2_MARKETA_BILA_CRAWLER_H
