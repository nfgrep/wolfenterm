//main.c
//nfgrep 2020
#include "init.h"
#include "geom.h"
#include "raycast.h"
#include "player.h"
#include "map.h"

#include <stdio.h>
#include <stdlib.h>
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

    map m1;
    
    player plr;

    init("../map.txt", &m1, &plr);

    int dists[PLAYER_NUM_RAYS];
    printf("segg2?");    
    //Starting input_thread()
    pthread_t thid;
    pthread_create(&thid, NULL, input_thread, NULL);

    //GAMELOOP
    while(1)
    {
        //Casting all rays for player and storing result in dists
        cast_rays(dists, &m1, &plr);
        
        //TODO: Remove. Part of global var baddness
        if(inp_key == 'd')
        {
            plr.rot += 0.05;
        }
        else if(inp_key == 'a')
        {
            plr.rot -= 0.05;
        }
        inp_key = 0;
        //printf("### %c ###\n", inp_key);
        
        //Printing results of ray dists
        for(int i=0; i< PLAYER_NUM_RAYS; i++)
        {
            printf("dist: %d\n",dists[i]);
            int h = 40 - dists[i];
            for(int j=0; j< h; j++)
            {
                printf("X");
            }
        }
        printf("\n");
        clock_t stime = clock();
        while(clock() < stime + 100000);
        printf("plr.rot: %f\n",plr.rot);
    }

    return 0;

}
