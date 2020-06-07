#ifndef GEOM_H
#define GEOM_H

#include "map.h"

#define PI 3.14159265358979323846
#define PI_2 1.57079632679489661923

//Rotates (x1,y1) about (x0,y0) by angle in radians
void rot_point(int x0, int y0, int* x1, int* y1, double rot);

typedef struct
{
    int x;
    int y;
    
}point;

typedef struct
{
    double x0;
    double x1;
    double y0;
    double y1;
}line;

#endif
