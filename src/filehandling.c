#include "../inc/player.h"
#include "../inc/filehandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: make this more generic
int read_file(char* filename, player* p1, char*** m1)
{
    short ix=0, iy=0;
    char map[MAPMAX][MAPMAX] ={ 0 };
    FILE *fp;
    fp = fopen(filename,"r");
    char c = fgetc(fp);
    if(fp == NULL)
    {
        printf("Error opening file; does the file exist?");
        return 1;
    }
    else
    {
        //Filling arr on stack with file contents
        while(!feof(fp) && ix < MAPMAX)
        {
            iy=0;
            while( c != '\n' && iy < MAPMAX)
            {
                map[ix][iy] = c;
                printf("added to map: %c\n",c);
                c = fgetc(fp);
                if(c == PLAYER_ID_CHAR)
                {
                    printf("playerchar found: %c, at %d,%d\n",c,ix,iy);
                    p1->pos.x = ix;
                    p1->pos.y = iy;
                    p1->opos.x = ix;
                    p1->opos.y = iy;
                }
                iy++;
            }
            c = fgetc(fp);
            ix++;
        }

        fclose(fp);

        printf("maplen = %d x %d\n",ix,iy);
        
        //Allocating number of lines onto heap
        char** hmap = (char**) malloc(ix*sizeof(char*)+1);
    
        //Allocating characters within lines onto heap
        for(char k=0; k<ix+1; k++)
        {
            *(hmap+k) = (char*) malloc(iy+1);
       
            //Copying contents of stack arr onto heap
            memcpy(*(hmap+k),*(map+k),iy+1);
        }

        *m1 = hmap;

        return 0;
    }
}
        
            
    
