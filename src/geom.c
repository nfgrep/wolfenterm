#include "../inc/geom.h"
#include "../inc/player.h"
#include "../inc/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//TODO: clean up all these includes!?

void rot_point(int x0, int y0, int* x1, int* y1, double angle)
{
    double cosT = cos(angle);
    double sinT = sin(angle);
    double xN = (*x1 - x0), yN = (*y1 - y0);
    *x1 = (((cosT * xN) + ((sinT * -1.0) * yN)) + x0);
    *y1 = (((sinT * xN) + (cosT * yN)) + y0);
}

