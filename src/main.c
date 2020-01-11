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

    p1.rot = 0.78539816339; // pi/4 - 45deg in rad

    //Reading map data from file and storing in data member of map struct
    if(read_file("../map.txt", &p1, &m1))
    {
        exit(1);
    }
    
    cast_ray(ray_results, &m1, &p1);
    return 0;

}
