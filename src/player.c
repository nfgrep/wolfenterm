#include "../inc/player.h"
#include "../inc/geom.h"

int update_player(player* plr)
{
    //Updating the player rays to the current player position
    for(int i=0;i<PLAYER_NUM_RAYS;i++)
    {
        //plr->rays[i].x += plr->pos.x;
        //plr->rays[i].y += plr->pos.y;
        rot_point_abt(plr->pos.x,plr->pos.y,&plr->rays[i].x,&plr->rays[i].y,plr->rot);
    }
}
