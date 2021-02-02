#include "cub3d.h"

void BubbleSort(int inde)
{
    int i, g_j, temp;
    for (i = 0; i < (inde - 1); ++i)
    {
        for (g_j = 0; g_j < inde - 1 - i; ++g_j )
        {
            if (g_mapcount[g_j].lenghtx < g_mapcount[g_j+1].lenghtx)
            {
                temp = g_mapcount[g_j+1].lenghtx;
                g_mapcount[g_j+1].lenghtx = g_mapcount[g_j].lenghtx;
                g_mapcount[g_j].lenghtx = temp;
            }
        }
    }
}
void fd_tab2()
{
    int c = 0;
    
    c = ft_valid_map();
  
        if(c == 1)
        g_line[inde] = ft_strdup(g_map[g_y_len]);
        else
        {
            ft_putstr("error in g_map");
            exit(0);
        }  
}

void ft_check_virg()
{
    int i;

    i = 0;
    while(g_check[1][i])
    {
        if(g_check[1][i] == ',')
            g_split++;
        i++;
    }
}

void ft_check_errormap(int p)
{
    if(strchr("1 0", g_map[g_y_len][0]) && g_mapcount[g_t].mapx > 0)
    {
        ft_return();
        ft_switch_space();
        if(g_dontenteragain == 10 && g_mapcount[g_t - 1].mapx == 0)
        {
            ft_putstr("invalid mapox");
            exit(0);
        }         
        if (g_dontenteragain == 0)
        {
            g_k = ft_first_line();
            if (g_k == 0)
            {
                ft_putstr("invalid mape");
                exit(0);
            }
            else if (g_k == 1)
            {
                g_line[inde] = ft_strdup(g_map[g_y_len]);
                g_dontenteragain = 10;
            }
        }
        else
            fd_tab2();
        g_mapcount[p].linex = ft_strlen(g_line[inde]);
        inde++;
        p++;
    }
}



void ft_switch_space()
{
    int i;
    int g_j;
    int f;

    i = 0;
    g_j = 0;
    f = 0;
    char *tmp;
    int variable;
    char *str;
    variable = ft_strlen(g_map[g_y_len]);
        i = g_mapcount[0].lenghtx - variable;
        str = malloc(sizeof(char) * i + 1);
        f = 0;
        while(i > f)
        {
            str[f] = ' ';
            f++;
        }
        str[f] = '\0';
        tmp = ft_strdup(g_map[g_y_len]);
        free(g_map[g_y_len]);
        g_map[g_y_len] = ft_strjoin(tmp, str);
        free(tmp);
        free(str);
}