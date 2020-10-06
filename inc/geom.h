#ifndef GEOM_H
#define GEOM_H


typedef struct point
{
	int x;
	int y;
}point;

typedef struct fpoint
{
    double x;
    double y;
}fpoint;

typedef struct line
{
    int x0;
    int x1;
    int y0;
    int y1;
}line;

void rot_point_abt(int x0, int y0, int* x1, int* y1, double rot);

void rot_fpoint_abt(int x0, int y0, double* x1, double* y1, double rot);

void cast_rays(int* ray_results, char** map, line* rays);

void cast_rays_from(int* ray_results, char** map, fpoint from, fpoint* to);

#endif
