
#include "cub3d.h"

void ft_check()
{
    static int p = 0;
   
if(*g_check != NULL)
{
     if (strcmp(g_check[0],"R") == 0)
        ft_check_R();
     else if(strcmp(g_check[0],"NO") == 0)
         ft_check_NO();
     else if(strcmp(g_check[0],"WE") == 0)
         ft_check_WE();
     else if(strcmp(g_check[0],"SO") == 0)
         ft_check_SO();
     else if(strcmp(g_check[0],"EA") == 0)
         ft_check_EA();   
     else if(strcmp(g_check[0],"S") == 0)
        ft_check_S();
     else if(strcmp(g_check[0],"C") == 0)
        ft_check_C();
      else if(strcmp(g_check[0],"F") == 0)
        ft_check_F();
     else if(strchr("1 0", g_map[g_y_len][0]) && g_mapcount[g_t].mapx > 0)
        ft_check_errormap(p);
        else
        {
            ft_putstr("weird character");
            exit(0);
        }
}
}

void ft_check_NO()
{
    g_direction.no++;
    if(counter != 2)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_f = check_valid(g_check[1]);
    if (g_f == 1)
        g_textu1 = ft_texture(g_check[1], g_textu1);
    if (g_f == 0)
    {
        ft_putstr("invalidmap\n");
        exit (0);
    }
    g_calcul_parameter++;
}
void ft_check_R()
{
    g_direction.r++;
    if(counter != 3)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_width = ft_atoi_w(g_check[1]);
    g_height = ft_atoi_h(g_check[2]);
    if(g_width > 2550 || g_height > 1440)
    {
        if (g_width > 2550)
            g_width = 2550;
        if (g_height > 1440)
            g_height = 1440;
    }
    if(g_width < 0 || g_height < 0)
    {
        ft_putstr("invalid resolution\n");
        exit (0);
    }
    ft_check_resolution();
    g_calcul_parameter++;
}
void ft_check_WE()
{
    g_direction.we++;
    if(counter != 2)
    {
        ft_putstr("missing parameter");
        exit(0);
    }
    g_f = check_valid(g_check[1]);
    if (g_f == 1)
        g_textu2 = ft_texture(g_check[1], g_textu2);
    if (g_f == 0)
    {
        ft_putstr("invalidmap\n");
        exit (0);
    }
    g_calcul_parameter++;
}

void ft_check_SO()
{
     g_direction.su++;
         if(counter != 2)
        {
            ft_putstr("missing parameter");
            exit(0);
        }
         g_f = check_valid(g_check[1]);
         if (g_f == 1)
            g_textu3 = ft_texture(g_check[1], g_textu3);
            if (g_f == 0)
            {
                ft_putstr("invalidmap\n");
                exit (0);
            }
       
        g_calcul_parameter++;
}