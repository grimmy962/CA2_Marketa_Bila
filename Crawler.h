//
// Created by bilam on 23/04/2024.
//

#ifndef CA2_MARKETA_BILA_CRAWLER_H
#define CA2_MARKETA_BILA_CRAWLER_H


#include "Bug.h"

class Crawler: public Bug {

protected:
    virtual void move();


public:
    Crawler(int id, int x, int y, int direction, int size);
};


#endif //CA2_MARKETA_BILA_CRAWLER_H
