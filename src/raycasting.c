#include "../inc/raycasting.h"
#include "../inc/player.h"
#include "../inc/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void rot_line_abt_p0(int x0, int y0, int* x1, int* y1, double rot)
{
    double cosT = cos(rot);
    double sinT = sin(rot);
    double xN = (*x1 - x0), yN = (*y1 - y0);
    *x1 = (((cosT * xN) + ((sinT * -1.0) * yN)) + x0);
    *y1 = (((sinT * xN) + (cosT * yN)) + y0);
}

void cast_rays(int* dists, map* m1, player* p1)
{
    int dist_count;
    int px = p1->x, py = p1->y;
    int x0, y0, x1, y1;
    int i, len = PLAYER_NUM_RAYS * 2;

    //Iterates over arr of player rays
    for(i=0; i<len; i+=2)
    {
        dist_count = 0;
        x0 = px;
        y0 = py;

        //Have to add x0,y0 here, as rays[] is relative to player
        x1 = p1->rays[i] + x0;
        y1 = p1->rays[i+1] + y0;

        //Adding players rotation to each ray
        rot_line_abt_p0(x0,y0,&x1,&y1,p1->rot);

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
    
        while(m1->data[y0][x0])
        {
            //printf("CURR: %c\n", m1->data[y0][x0]);
            if(x0==x1 && y0==y1) break;
            if(m1->data[y0][x0] != '0' && m1->data[y0][x0] != '2') break;
            e2 = 2*err;
            if(e2 >= dy)
            {
                err += dy;
                x0 += sx;
                dist_count++;
            }
            if(e2 <= dx)
            {
                err += dx;
                y0 += sy;
                dist_count++;
            }
        }
        printf("(%d,%d): %c as dec: %d\n",x0,0,m1->data[y0][x0],m1->data[y0][x0]);
        dists[i/2] = dist_count;
    }
}




