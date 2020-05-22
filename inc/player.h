#ifndef PLAYER_H
#define PLAYER_H

#include "geom.h"

#define PLAYER_ID_CHAR '2'
#define PLAYER_NUM_RAYS 41
#define PLAYER_RAY_LEN 40

typedef struct p
{
    unsigned int x;
    unsigned int y; 
    //players rotation in radians
    double rot;
    //The (x1,y1) of each ray relative to player
    point rays[PLAYER_NUM_RAYS];
}player;

#endif
