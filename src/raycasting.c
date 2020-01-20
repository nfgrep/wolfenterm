#include "../inc/raycasting.h"
#include "../inc/player.h"
#include "../inc/map.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int cast_ray(int* ray_results, map* m1, player* p1)
{
    double slope = tan(p1->rot);
    double err = 0.0;
    double abslope = fabs(slope);
    int y = p1->y, x = p1->x;
    int y_step = (p1->rot > M_PI) ? -1 : 1;
    char steep = (abslope >= 1) ? 1 : 0;
    printf("cur_player: %d,%d - %f\n",p1->x,p1->y,p1->rot);
    printf("slope: %f\n",slope);
    //If steepline, swap x and y
    if(steep)
    {
        int tmp = x;
        x = y;
        y = tmp;
        while(m1->data[y][x])
        {
            err += abslope;
            if(err >= 0.5)
            {
                y+=y_step;
                err -= 1.0;
            }
            x++;
            printf("Steep: Cur Char: %c\n",m1->data[y][x]);
        }
    }
    else
    {
        while(m1->data[y][x])
        {
            err += abslope;
            if(err >= 0.5)
            {
                y+=y_step;
                err -= 1.0;
            }
            x++;
            printf("Cur Char: %c\n",m1->data[y][x]);
        }
    }
    return 0;
}




