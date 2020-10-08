#include "../inc/player.h"
#include "../inc/geom.h"

int update_player(player* plr)
{
    double px_diff = plr->pos.x - plr->opos.x;
    double py_diff = plr->pos.y - plr->opos.y;
    double pr_diff = plr->rot - plr->orot;
    
    plr->opos = plr->pos;
    plr->orot = plr->rot;

    // Updating the player rays to the current player position
    for(int i=0;i<PLAYER_NUM_RAYS;i++)
    {
        plr->rays[i].x += px_diff;
        plr->rays[i].y += py_diff;
        rot_fpoint_abt(plr->pos.x,plr->pos.y,&plr->rays[i].x,&plr->rays[i].y,pr_diff);
        plr->rays[i].angle_offset += pr_diff;
    }
}
