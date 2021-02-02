#include "cub3d.h"

void ft_return()
{
    if(g_direction.c != 1 || g_direction.we != 1|| g_direction.ea != 1 || g_direction.f != 1 || g_direction.su != 1 || g_direction.no != 1 || g_direction.r != 1 || g_direction.s != 1)
    {
        ft_putstr("missing or multiple parameter");
        exit(0);
    }
}
void ft_map_traitement1(int lenght,int fd)
{
    BubbleSort(lenght);
    g_y_len = 0;
    while(g_y_len <= lenght)
    {  
        g_mapcount[g_t].mapx = ft_strlen(g_map[g_y_len]);
        
        if(g_mapcount[g_t].mapx > 0)
        {   
            g_split = 0;
            if(g_calcul_parameter <= 8)
                g_check = ft_split(g_map[g_y_len],' ');
            ft_check(fd);
            if(g_calcul_parameter <= 8)
                ft_free_l3alam1();
        }       
        g_t++;
        g_y_len++;
    }
    ft_return();
    inde--;
    ft_last_line();
    ft_free_l3alam(g_map);
    g_line[++inde] = NULL;
    g_y_len++;
}
int  fd_tab(int fd)
{
    char **str;
    int c = 0;
    int lenght = 0;
    g_calcul_parameter = 0;
    g_y_len = 0;
    g_map = malloc(sizeof(char *) * (g_indexo + 2));
    str = malloc(sizeof(char *) * (g_indexo + 2));
    g_empty_line = 0;
    while(get_next_line(fd,&str[lenght]))
    {
        if(ft_strlen(str[lenght]) == 0)
            g_empty_line++;
        g_map[g_y_len] = ft_strdup(str[lenght]);
        if(ft_strchr("1 0", str[lenght][0]))
            g_mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
        lenght++;
        g_y_len++;
    }
    g_map[g_y_len] = ft_strdup(str[lenght]);
    g_mapcount[lenght].lenghtx = ft_strlen(str[lenght]);
    g_map[++g_y_len] = NULL;
    str[g_y_len] = NULL;
    ft_free_l3alam(str);
    ft_map_traitement1(lenght,c);
}
int check_valid(char *g_check)
{
    if(strcmp(strrchr(g_check ,'.'),".xpm") == 0)
        return (1);
    return(0);
}
void ft_check_weird()
{
    int i = 0;
    while(g_check[1][i])
    {
        if(!((g_check[1][i] >= '0' && g_check[1][i] <= '9') || g_check[1][i] == ','))
        {
            ft_putstr("Weird parameter");
            exit(0);
        }
        i++;
    }
}