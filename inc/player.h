#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_ID_CHAR '2'
#define PLAYER_NUM_RAYS 7

typedef struct p
{
    unsigned int x;
    unsigned int y; 
    double rot; //players rotation in radians
    //The x1 points for the end of each ray relative to the player
    int rays[PLAYER_NUM_RAYS*2];
}player;

#endif
