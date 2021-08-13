#include "../inc/player.h"
#include "../inc/geom.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void rot_point_abt(int x0, int y0, int* x1, int* y1, double rot)
{
    double cosT = cos(rot);
    double sinT = sin(rot);
    double xN = (*x1 - x0), yN = (*y1 - y0);
    *x1 = (((cosT * xN) + ((sinT * -1.0) * yN)) + x0);
    *y1 = (((sinT * xN) + (cosT * yN)) + y0);
}

void rot_fpoint_abt(int x0, int y0, double* x1, double* y1, double rot)
{
    double cosT = cos(rot);
    double sinT = sin(rot);
    double xN = (*x1 - x0), yN = (*y1 - y0);
    *x1 = (((cosT * xN) + ((sinT * -1.0) * yN)) + x0);
    *y1 = (((sinT * xN) + (cosT * yN)) + y0);
}

void cast_rays(int* dists, char** m1, line* rays)
{
    int dist_count;
    int x0, y0, x1, y1;
    int i, len = PLAYER_NUM_RAYS;

    //Iterates over arr of player rays
    for(i=0; i<len; i++)
    {
        dist_count = 0;
        x0 = rays[i].x0;
        y0 = rays[i].y0;
	
        x1 = rays[i].x1;
        y1 = rays[i].y1;

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
   
        while(m1[y0][x0])
        {
            //printf("CURR: %c\n", m1->data[y0][x0]);
            if(x0==x1 && y0==y1) break;
            if(m1[y0][x0] != '0' && m1[y0][x0] != '2') break;
            e2 = 2*err;
            if(e2 >= dy)
            {
                err += dy;
                x0 += sx;
                dist_count+=16;
            }
            if(e2 <= dx)
            {
                err += dx;
                y0 += sy;
                dist_count+=16;
            }
        }
        //printf("(%d,%d): %c as dec: %d\n",x0,0,m1->data[y0][x0],m1->data[y0][x0]);
        dists[i] = dist_count;
    }
}

void cast_rays_from(int* dists, char** m1, point ray_start, ray* ray_ends)
{
    int dist_count;
    int x0 = ray_start.x, y0 = ray_start.y;
    int x1, y1;
    int i;

    //TODO: make cast_ray function
    //Iterates over arr of player rays
    for(i=0; i<PLAYER_NUM_RAYS; i++)
    {
        dist_count = 0;
        	
        printf("ray_ends[%d]: (%d,%d)\n angle_offset: %f\n",i,ray_ends[i].x,ray_ends[i].y,ray_ends[i].angle_offset);
        x0 = ray_start.x;
        y0 = ray_start.y;
        x1 = ray_ends[i].x;
        y1 = ray_ends[i].y;

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
   
        while(m1[y0][x0])
        {
            //printf("CURR: %c\n", m1->data[y0][x0]);
            if(x0==x1 && y0==y1) break;
            if(m1[y0][x0] != '0' && m1[y0][x0] != '2') break;
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
        printf("(%d,%d): %c as dec: %d\n",x0,y0,m1[y0][x0],m1[y0][x0]);
        dists[i] = dist_count * cos(ray_ends[i].angle_offset);
    }
}

void get_view_dists(int* dists, char** m1, point ray_start, ray* ray_ends, double plr_rot)
{
    int dist_count;
    int x0 = ray_start.x, y0 = ray_start.y;
    int x1, y1;
    int i;

    //TODO: make cast_ray function
    //Iterates over arr of player rays
    for(i=0; i<PLAYER_NUM_RAYS; i++)
    {
        dist_count = 0;
            
        printf("ray_ends[%d]: (%d,%d)\n angle_offset: %f\n",i,ray_ends[i].x,ray_ends[i].y,ray_ends[i].angle_offset);
        x0 = ray_start.x;
        y0 = ray_start.y;
        x1 = ray_ends[i].x;
        y1 = ray_ends[i].y;

        //Bresenhams Line with int arith
        int dx = abs(x1-x0);
        int sx = x0<x1 ? 1 : -1;
        int dy = -abs(y1-y0);
        int sy = y0<y1 ? 1 : -1;
        int err = dx+dy, e2=0;
   
        while(m1[y0][x0])
        {
            //printf("CURR: %c\n", m1->data[y0][x0]);
            if(x0==x1 && y0==y1) break;
            if(m1[y0][x0] != '0' && m1[y0][x0] != '2') break;
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
        printf("(%d,%d): %c as dec: %d\n",x0,y0,m1[y0][x0],m1[y0][x0]);
        dists[i] = dist_count * cos(ray_ends[i].angle_offset);
    }
}


