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
    int y = p1->y, x = p1->x;
    printf("cur_player: %d,%d - %f\n",p1->x,p1->y,p1->rot);
    printf("slope: %f\n",slope);
    while(m1->data[y][x])
    {
        err += slope;
        if(err >= 0.5)
        {
            y++;
            err -= 1.0;
        }
        x++;
        printf("Cur Char: %c\n",m1->data[y][x]);
    }
    return 0;
}




