#include "../inc/filehandling.h"
#include "../inc/player.h"
#include "../inc/geom.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   //TODO: Remove
#include <unistd.h>
#include <pthread.h>
#include <termios.h>    //TODO: can remove?? Need for input, may migrate to curses soon.
#include <time.h>   //TODO: can remove? Used for delaying gameloop

//TODO: Use Mutex, global vars bad, memory hazards!
//Global for which key is currently pressed
unsigned char inp_key = 0;

void *input_thread(void *vargp)
{
    //Setting term input to not req return key
    struct termios attr;
    tcgetattr(0, &attr);
    attr.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &attr);

    while(1)
    {
        inp_key = getchar();
        //printf("Input: %c, %d\n",inp_key);
    }
}
int main()
{

    char** m1;
    
    player p1;

    int dists[PLAYER_NUM_RAYS];
    
    p1.pos.x = 0;
    p1.pos.y = 0;
    p1.opos.x = 0;
    p1.opos.y = 0;

    //Must start at 0
    p1.rot = 0;
    p1.orot = 0;

    //TODO: make this an arg
    //Reading map data from file and storing in data member of map struct
    char* map_fname = "../map.txt";
    if(read_file(map_fname, &p1, &m1)) exit(1);

    //Generating/Initializing player rays
    double rot_inc = FOV/PLAYER_NUM_RAYS;
    double curr_rot = (PLAYER_NUM_RAYS%2) ?  p1.rot + rot_inc : p1.rot + (rot_inc/2);
    double max_rot = p1.rot + (FOV/2.0);
    int ir, end_idx = PLAYER_NUM_RAYS-1;

    // initializing rays to 0 position
    for(ir=0;ir<PLAYER_NUM_RAYS;ir++)
    { 
        p1.rays[ir].x = p1.pos.x;
        p1.rays[ir].y = PLAYER_RAY_LEN;
    }

    // generating and setting rays
    for(ir=(PLAYER_NUM_RAYS/2)-1;ir>=0;ir--)
    {
        printf("rotating by: %f\n",curr_rot);
        rot_fpoint_abt(p1.pos.x,p1.pos.y,&p1.rays[ir].x,&p1.rays[ir].y,curr_rot); 
        p1.rays[ir].angle_offset = curr_rot;
        rot_fpoint_abt(p1.pos.x,p1.pos.y,&p1.rays[end_idx-ir].x,&p1.rays[end_idx-ir].y,-curr_rot); 
        p1.rays[end_idx-ir].angle_offset = -curr_rot;
        printf("pos: %d and %d",ir,end_idx-ir);
        printf("--after rot-- p1.rays[ir].x: %d, p1.rays[ir].y: %d\n",p1.rays[ir].x,p1.rays[ir].y);
        printf("--after rot-- p1.rays[ir].x: %d, p1.rays[ir].y: %d\n",p1.rays[end_idx-ir].x,p1.rays[end_idx-ir].y);
        curr_rot += rot_inc;
    }

    for(ir=0;ir<40;ir++)
    {
        for(int ic=0;ic<20; ic++)
        {
            printf("%c",m1[ic][ir]);
        }
        printf("\n");
    }

    //Starting input_thread()
    pthread_t thid;
    pthread_create(&thid, NULL, input_thread, NULL);

    //GAMELOOP
    while(1)
    {
        //Casting all rays for player and storing result in dists
        cast_rays_from(dists, m1, p1.pos, p1.rays);
        
        printf("player:\n pos: (%d,%d)\n opos(%d,%d)\n rot(%f)\n orot(%f)\n",p1.pos.x,p1.pos.y,p1.opos.x,p1.opos.y,p1.rot,p1.orot);

        update_player(&p1);
        printf("player rotation: %f\n",p1.rot); 
        //TODO: Remove. Part of global var baddness
        if(inp_key == 'd')
        {
            p1.rot -= 0.1;
        }
        else if(inp_key == 'a')
        {
            p1.rot += 0.1;
        }
        else if(inp_key == 's')
        {
            p1.pos.y -= 1;
        }
        else if(inp_key == 'w')
        {
            p1.pos.y += 1;
        }
        inp_key = 0;
        //printf("### %c ###\n", inp_key);
        
        //Printing results of ray dists
        for(int i=0; i< PLAYER_NUM_RAYS; i++)
        {
            printf("\n");
            int h = PLAYER_RAY_LEN - dists[i];
            for(int j=0; j< h; j++)
            {
                printf("X");
            }
        }
        printf("\n");
            clock_t stime = clock();
            while(clock() < stime + 100000);
        //printf(" p1.rot: %f\n",p1.rot);
    }

    return 0;

}
