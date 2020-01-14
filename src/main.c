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
    
    cast_ray(ray_results, &m1, &p1);
    return 0;

}
