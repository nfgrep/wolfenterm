#ifndef RAYCASTING_H
#define RAYCASTING_H
#define NUM_RAYS 7
#define RAY_LEN 40
#include "player.h"
#include "map.h"

int cast_ray(int* ray_results, map* m1, player* p1);

#endif
