#ifndef GEOM_H
#define GEOM_H


typedef struct point
{
	int x;
	int y;
}point;

typedef struct line
{
    int x0;
    int x1;
    int y0;
    int y1;
}line;

void rot_point_abt(int x0, int y0, int* x1, int* y1, double rot);

void cast_rays(int* ray_results, char** map, line* rays);

void cast_rays_from(int* ray_results, char** map, point from, point* to);

#endif
