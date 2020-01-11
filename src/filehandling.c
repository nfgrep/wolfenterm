#include "../inc/player.h"
#include "../inc/filehandling.h"
#include "../inc/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(char* filename, player* p1, map* m1)
{
    short i=1, j=1;
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
            j=1;
            while( c != '\n' && j < MAPMAX)
            {
                c = fgetc(fp);
                map[i][j] = c;
                if(c == PLAYER_IDENT_CHAR)
                {
                    printf("playerchar found: %c, at %d,%d\n",c,j,i);

                    p1->x = j;
                    p1->y = i;
                }
                j++;
            }

            i++;
            c = fgetc(fp);
        }

        fclose(fp);

        //Setting map size for reference outside of function
        m1->x_len = j-1;
        m1->y_len = i-1;

        //Allocating number of lines onto heap
        char** hmap = (char**) malloc(i*sizeof(char*)+1);
    
        //Allocating characters within lines onto heap
        for(char k=0; k<i+1; k++)
        {
            *(hmap+k) = (char*) malloc(j+1);
       
            //Copying contents of stack arr onto heap
            memcpy(*(hmap+k),*(map+k),j+1);
        }

        m1->data = hmap;

        return 0;
    }
}
        
            
    
