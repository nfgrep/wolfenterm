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
    int xN = (*x1 - x0), yN = (*y1 - y0);
    *x1 = (((cosT * xN) + ((sinT * -1) * yN)) + x0);
    *y1 = (((sinT * xN) + (cosT * xN)) + y0);
}

int cast_rays(int* ray_results, map* m1, player* p1)
{
    /*--TODO--
        - change len to a const
        - make the loop iter 1 less, move declaration of x1 out
    */

    int x0, y0;

    int i, len = 14;
    for(i=0; i<len; i+=2)
    {
        x0 = p1->x;
        y0 = p1->y;
        int x1 = p1->rays[i];
        int y1 = p1->rays[i+1];
        printf("y1: %d\n",y1);

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
    
        while(m1->data[y0][x0])
        {
            printf("CURR: %c\n", m1->data[y0][x0]);
            if(x0==x1 && y0==y1) break;
            e2 = 2*err;
            if(e2 >= dy)
            {
                err += dy;
                x0 += sx;
            }
            if(e2 <= dx)
            {
                err += dx;
                y0 += sy;
            }
        }
    }
//Old code, using slope and float arith.
//    double slope = tan(p1->rot);
//    double err = 0.0;
//    double abslope = fabs(slope);
//    int y = p1->y, x = p1->x;
//    int y_step = (p1->rot > M_PI) ? -1 : 1;
//    char steep = (abslope >= 1) ? 1 : 0;
//    printf("cur_player: %d,%d - %f\n",p1->x,p1->y,p1->rot);
//    printf("slope: %f\n",slope);
//    //If steepline, swap x and y
//    if(steep)
//    {
//        int tmp = x;
//        x = y;
//        y = tmp;
//        while(m1->data[y][x])
//        {
//            err += abslope;
//            if(err >= 0.5)
//            {
//                y+=y_step;
//                err -= 1.0;
//            }
//            x++;
//            printf("Steep: Cur Char: %c\n",m1->data[y][x]);
//        }
//    }
//    else
//    {
//        while(m1->data[y][x])
//        {
//            err += abslope;
//            if(err >= 0.5)
//            {
//                y+=y_step;
//                err -= 1.0;
//            }
//            x++;
//            printf("Cur Char: %c\n",m1->data[y][x]);
//        }
//    }
    return 0;
}




