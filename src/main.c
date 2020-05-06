#include "../inc/filehandling.h"
#include "../inc/raycasting.h"
#include "../inc/player.h"
#include "../inc/map.h"
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int main()
{
    map m1;
    player p1;
   
    p1.x = 0;
    p1.y = 0;

    //The 'tips' of each ray the player casts
    p1.rays[0] = 40;
    p1.rays[1] = -15;

    p1.rays[2] = 40;
    p1.rays[3] = -10;

    p1.rays[4] = 40;
    p1.rays[5] = -5;

    p1.rays[6] = 40;
    p1.rays[7] = 0;

    p1.rays[8] = 40;
    p1.rays[9] = 5;

    p1.rays[10] = 40;
    p1.rays[11] = 10;

    p1.rays[12] = 40;
    p1.rays[13] = 15;



    int dists[PLAYER_NUM_RAYS];

    //p1.rot = 0.78539816339; // pi/4 - 45deg in rad
    //p1.rot = 1.0471975512; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 1.308996939; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 1.57079632679; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 0.26179938779; // pi/12 - shallow
    p1.rot = M_PI/2;

    //Reading map data from file and storing in data member of map struct
    if(read_file("../map.txt", &p1, &m1)) exit(1);
    
    //GAMELOOP
    while(p1.rot < 4.0)
    {
        cast_rays(dists, &m1, &p1);
        p1.rot += 0.01;
        
        for(int i=0; i< PLAYER_NUM_RAYS; i++)
        {
            printf("%d ",dists[i]);
        }
        printf("\n p1.rot: %f\n",p1.rot);
    }

    return 0;

}
