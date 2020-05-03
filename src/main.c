#include "../inc/filehandling.h"
#include "../inc/raycasting.h"
#include "../inc/player.h"
#include "../inc/map.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    map m1;
    player p1;
   
    p1.x = 0;
    p1.y = 0;

    //The 'tips' of each ray the player casts
    p1.rays[0] = 20;
    p1.rays[1] = -15;

    p1.rays[2] = 20;
    p1.rays[3] = -10;

    p1.rays[4] = 20;
    p1.rays[5] = -5;

    p1.rays[6] = 20;
    p1.rays[7] = 0;

    p1.rays[8] = 20;
    p1.rays[9] = 5;

    p1.rays[10] = 20;
    p1.rays[11] = 10;

    p1.rays[12] = 20;
    p1.rays[13] = 15;



    int ray_results[NUM_RAYS];

    //p1.rot = 0.78539816339; // pi/4 - 45deg in rad
    p1.rot = 1.0471975512; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 1.308996939; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 1.57079632679; // pi/3 - 60deg in rad, steeper than pi/4
    //p1.rot = 0.26179938779; // pi/12 - shallow

    //Reading map data from file and storing in data member of map struct
    if(read_file("../map.txt", &p1, &m1))
    {
        exit(1);
    }
    
    cast_rays(ray_results, &m1, &p1);
    return 0;

}
