#ifndef RAYCAST_H
#define RAYCAST_H

#include "player.h"
#include "map.h"

//Populates ray_results with distances of rays for player p1 in map m1
void cast_rays(int* ray_results, map* m1, player* plr);

#endif
