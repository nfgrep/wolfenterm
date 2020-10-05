#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_ID_CHAR '2'
#define PLAYER_NUM_RAYS 5
#define PLAYER_RAY_LEN 40
#define FOV 1.570796327
#include "geom.h"

typedef struct p
{
    unsigned int x;
    unsigned int y; 
    double rot; //players rotation in radians
    //The x1 points for the end of each ray relative to the player
    point rays[PLAYER_NUM_RAYS];
}player;

int update_player(player* plr);

#endif
