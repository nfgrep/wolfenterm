#include "player.h"

int update_player(player* plr)
{
    //Updating the player rays to the current player position
    for(int i=0;i<PLAYER_NUM_RAYS;i++)
    {
        plr->rays[i].x += plr->x;
        plr->rays[i].y += plr->y;
    }
}
