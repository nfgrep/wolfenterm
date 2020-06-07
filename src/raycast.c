//raycast.c
//nfgrep 2020
#include "raycast.h"
#include "geom.h"
#include "player.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//TODO: Lone function in file? Move to main?

void cast_rays(int* dists, map* m1, player* plr)
{
    int dist_count;
    int px = plr->x, py = plr->y;
    int x0, y0, x1, y1;
    int i;


    //Iterates over arr of player rays
    for(i=0; i<PLAYER_NUM_RAYS; i++)
    {
        dist_count = 0;
        
        x0 = plr->rays[i].x0;
        y0 = plr->rays[i].y0;

        x1 = plr->rays[i].x1;
        y1 = plr->rays[i].y1;

        //Adding players rotation to each ray
        rot_point(plr->x,plr->y,&x0,&y0,plr->rot);
        rot_point(plr->x,plr->y,&x1,&y1,plr->rot);

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
        printf("M1->DATA: %c", m1->data[0][0]);
    
        while(m1->data[y0][x0])
        {
            printf("CURR: %c\n", m1->data[y0][x0]);
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
        //printf("(%d,%d): %c as dec: %d\n",x0,0,m1->data[y0][x0],m1->data[y0][x0]);
        dists[i] = dist_count;
    }
}


