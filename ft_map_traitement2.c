#include "cub3d.h"

int ft_first_line()
{
    int i = 0;
    while(strchr("1 ",g_map[g_y_len][i]))
    {
        i++;
        if(g_map[g_y_len][i] == '\0')
            return(1);
    }
    return(0);
}
int ft_valid_map()
{
    int i = 0;

    while(strchr("012NWES ",g_map[g_y_len][i]))
    {
        i++;
        if(g_map[g_y_len][i] == '\0')
            return(1);
    }
    return(0);
}

void ft_check_zero1(int g_j, int i)
{
    if(g_line[g_j][0] == '0' || g_line[g_j][i + 1] == ' ' || g_line[g_j][i - 1] == ' ' || g_line[g_j - 1][i] == ' ' || g_line[g_j][i + 1] == '\0' || g_line[g_j + 1][i] == ' ')
    {
        ft_putstr("error in g_map");
        exit (0);
    }
}
void ft_check_sprite(int g_j, int i)
{
     if(g_line[g_j][i] == '2' && (g_line[g_j][i + 1] == ' ' || g_line[g_j][i - 1] == ' ' || g_line[g_j + 1][i] == ' '|| g_line[g_j - 1][i] == ' '))
    {
        ft_putstr("error in g_map");
        exit (0);
    } 
}
void ft_check_zero()
{
    int i;
    int g_j;

    i = 0;
    g_j = 0;
    while(g_line[g_j][i] && inde > g_j)
    {
        if(g_line[g_j][i] == '0')
            ft_check_zero1(g_j ,i);
        else if(g_line[g_j][i] == '2')
            ft_check_sprite(g_j, i);
        i++;
        if (g_line[g_j][i] == '\0' && inde > g_j)
        {
            i = 0;
            if (g_line[g_j + 1] == NULL)
                break;
            else
                g_j++;
        }
    }
}