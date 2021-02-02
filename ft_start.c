#include "cub3d.h"

int ray_Direction()
{
    g_rayFacingDown = 0;
    g_rayFacingUp = 0;
    g_rayFacingRight = 0;
    g_rayFacingLeft = 0;

    g_rayFacingDown = (deg(g_rotation) > 0 && deg(g_rotation) < 180) ? 1 : 0;
    g_rayFacingUp = !(g_rayFacingDown) ? 1 : 0;

    g_rayFacingRight = ((deg(g_rotation) > 0 && (deg(g_rotation) < 90)) || (deg(g_rotation) > 270 && (deg(g_rotation) < 360))) ? 1 : 0;
    g_rayFacingLeft = !(g_rayFacingRight) ? 1 : 0;
  
     return 0;

}
double Distance_between_HorVer(int x1,int y1, int x2, int y2)
{
    return sqrtf(powf((x2 - x1),2) + powf((y2 - y1),2));
}

void ft_intial_variable()
{
    g_WallHitX = 0;
    g_WallHitY = 0;
    g_distance = 0;
    g_sprite = 0;
    g_sprite_indicator = 0;
    g_wallHoriHit = 0;
    ray_Direction();
}

int loop_key()
{
    if (strcmp(g_chorfi,"--save") != 0)
    {
        mlx_hook(g_win_ptr,2,0,mlx_key_press,0);
        mlx_hook(g_win_ptr,3,0,key_release,0);
        mlx_hook(g_win_ptr,17,0L,ft_exit,0);
    }
    deal_key();
    if(swiitch == 1)
        mlx_put_image_to_window(g_mlx_ptr,g_win_ptr,g_image,0,0);
    return 0; 
}
int ft_last_line()
{
    int i = 0;
    while(strchr("1 ",g_line[inde][i]))
    {
        i++;
        if(g_line[inde][i] == ' ' && g_line[inde - 1][i] == '0')
            break;
        if(g_line[inde][i] == '\0')
            return(1);
    }
    ft_putstr("errormap\n");
    exit(0);
    return(0);
}
