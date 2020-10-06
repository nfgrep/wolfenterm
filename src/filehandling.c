#include "../inc/player.h"
#include "../inc/filehandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TODO: make this more generic
int read_file(char* filename, player* p1, char*** m1)
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
    else
    {
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
                    p1->pos.x = j;
                    p1->pos.y = i;
                    p1->opos.x = j;
                    p1->opos.y = i;
                }
                j++;
            }
            c = fgetc(fp);
            i++;
        }

        fclose(fp);

        printf("maplen = %d x %d\n",j,i);
        
        //Allocating number of lines onto heap
        char** hmap = (char**) malloc(i*sizeof(char*)+1);
    
        //Allocating characters within lines onto heap
        for(char k=0; k<i+1; k++)
        {
            *(hmap+k) = (char*) malloc(j+1);
       
            //Copying contents of stack arr onto heap
            memcpy(*(hmap+k),*(map+k),j+1);
        }

        *m1 = hmap;

        return 0;
    }
}
        
            
    
