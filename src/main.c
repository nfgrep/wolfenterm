#include "../inc/filehandling.h"
#include "../inc/raycasting.h"
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
    }geom
int main()
{

    char** m1;
    
    player p1;

    int dists[PLAYER_NUM_RAYS];
    
    p1.x = 0;
    p1.y = 0;

    p1.rot = M_PI/2;

    //The 'tips' of each ray the player casts
//    p1.rays[0] = 40;
//    p1.rays[1] = -15;
//
//    p1.rays[2] = 40;
//    p1.rays[3] = -10;
//
//    p1.rays[4] = 40;
//    p1.rays[5] = -5;
//
//    p1.rays[6] = 40;
//    p1.rays[7] = 0;
//
//    p1.rays[8] = 40;
//    p1.rays[9] = 5;
//
//    p1.rays[10] = 40;
//    p1.rays[11] = 10;
//
//    p1.rays[12] = 40;
//    p1.rays[13] = 15;
	

    //Reading map data from file and storing in data member of map struct
    if(read_file("../map.txt", &p1, &m1)) exit(1);

    //Generating player rays
    double curr_rot = p1.rot - (FOV/2.0);
    double max_rot = p1.rot + (FOV/2.0);
    double rot_inc = FOV/PLAYER_NUM_RAYS;

    while(curr_rot <= max_rot)
    {
        rot_line_abt_p0(p1.x,p1.y,p1.rays[i].x,p1.rays[i].y,curr_rot ); 
        curr_rot += rot_inc;
    }

    //Starting input_thread()
    pthread_t thid;
    pthread_create(&thid, NULL, input_thread, NULL);
/*
    //GAMELOOP
    while(1)
    {
        //Casting all rays for player and storing result in dists
        cast_rays(dists, &m1, &p1);
        
        //TODO: Remove. Part of global var baddness
        if(inp_key == 'd')
        {
            p1.rot += 0.1;
        }
        else if(inp_key == 'a')
        {
            p1.rot -= 0.1;
        }
        inp_key = 0;
        //printf("### %c ###\n", inp_key);
        
        //Printing results of ray dists
        for(int i=0; i< PLAYER_NUM_RAYS; i++)
        {
            printf("\n");
            int h = 40 - dists[i];
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
*/
    return 0;

}
