#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_ID_CHAR '2'
#define PLAYER_NUM_RAYS 30
#define PLAYER_RAY_LEN 40
#define FOV 1.570796327
#include "geom.h"

typedef struct p
{
    // opos and orot are "old rot" and "old pos"
    // used in update_player to rotate and shift the
    // rays[] to reflect the difference on each iter of gameloop
    point pos;
    point opos;
    double rot;
    double orot;
    // The x1 points for the end of each ray relative to the player
    ray rays[PLAYER_NUM_RAYS];
}player;

int update_player(player* plr);

#endif
