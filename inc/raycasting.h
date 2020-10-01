#ifndef RAYCASTING_H
#define RAYCASTING_H
#define RAY_LEN 40
#include "player.h"
#include "map.h"

typedef struct point
{
	unsigned int x;
	unsigned int y;
}point;

void cast_rays(int* ray_results, map* m1, player* p1);

#endif
