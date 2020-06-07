//init.c
//nfgrep 2020
#include "player.h"
#include "init.h"
#include "map.h"
#include "geom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TODO: static map the ray points, screw all the rotation nonsense.
//TODO: prittify me, is short rly necessary? might be slower bc alignment??

int init(char* filename, map* m, player* plr)
{
    short i=0, j=0;
    char map[MAPMAX][MAPMAX] ={ 0 };
    FILE *fp;
    fp = fopen(filename,"r");
    char c = fgetc(fp);
    if(fp == NULL)
    {
        printf("Error opening file; does the file exist?");
        return 1;
    }

    //Filling arr on stack with file contents
    while(!feof(fp) && i < MAPMAX)
    {
        j=0;
        while( c != '\n' && j < MAPMAX)
        {
            map[i][j] = c;
            printf("added to map: %c\n",c);
            c = fgetc(fp);
            if(c == PLAYER_ID_CHAR)
            {
                printf("playerchar found: %c, at %d,%d\n",c,j,i);
                plr->x = j;
                plr->y = i;
            }
            j++;
        }
        c = fgetc(fp);
        i++;
    }

    fclose(fp);

    //Setting map size for reference outside of function
    m->x_len = j+1;
    m->y_len = i+1;

    printf("maplen = %d x %d",j,i);
    
    //Allocating number of lines onto heap
    char** hmap = (char**) malloc(i*sizeof(char*)+1);

    //Allocating characters within lines onto heap
    for(char k=0; k<i+1; k++)
    {
        *(hmap+k) = (char*) malloc(j+1);
   
        //Copying contents of stack arr onto heap
        memcpy(*(hmap+k),*(map+k),j+1);
    }

    m->data = hmap;

    plr->rot = 0.0;


    line ln1;
    ln1.x0 = plr->x;
    ln1.y0 = plr->y;
    ln1.x1 = ln1.x0 + PLAYER_RAY_LEN;
    ln1.y1 = ln1.y0;
    line ln2 = ln1;

    int
    rmid = (PLAYER_NUM_RAYS - 1)/2,
    ir;

    printf("PLAYER_NUM_RAYS: %d\n",PLAYER_NUM_RAYS);
    printf("rmid: %d\n",rmid);
    
    plr->rays[rmid] = ln1;
    
    //Initing player rays via rotation: 
    /*double curangle = plr->rot;
    for(ir=1; ir<rmid+1; ir++)
    {
        curangle += 0.01;
        printf("FOR: plr->rays[%d]\n",rmid+ir);
        rot_point(0, 0, &p1.x, &p1.y, curangle);
        printf("p1.x: %d, p1.y: %d angle: %f\n",p1.x, p1.y, curangle);
        plr->rays[rmid+ir] = p1;
        rot_point(0, 0, &p2.x, &p2.y, -curangle);
        printf("FOR: plr->rays[%d]\n",rmid-ir);   
        printf("pi2.x: %d, p2.y: %d angle: %f\n",p2.x, p2.y, -curangle);
        plr->rays[rmid-ir] = p2;
    }
    for(int i=0; i<PLAYER_NUM_RAYS; i++) 
    {
        printf("plr.rays[%d]of%d: (%d,%d)\n",i,PLAYER_NUM_RAYS,plr->rays[i].x, plr->rays[i].y);
    }*/

    //Initing player rays via static values:
    for(ir=1; ir<rmid+1; ir++)
    {
        printf("FOR: plr->rays[%d]\n",rmid+ir);
        ln1.y0 += 0.2;
        ln1.y1 += 0.2;
        plr->rays[rmid+ir] = ln1;
        printf("ln1.x0: %d, ln1.y0: %d\n",ln1.x0, ln1.y0);
        printf("FOR: plr->rays[%d]\n",rmid-ir);   
        ln2.y0 -= 0.2;
        ln2.y1 -= 0.2;
        plr->rays[rmid-ir] = ln2;
        printf("ln2.x0: %d, ln2.y0: %d\n",ln2.x0, ln2.y0);
    }

    printf("Segg?\n");
    return 0;
}
        

    
