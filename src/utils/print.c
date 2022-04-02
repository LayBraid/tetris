/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

char *get_space(int max, int before, int after)
{
    char *tmp = "";

    for (int i = 0; i < max - before - after; i++)
        tmp = my_strcat_c(tmp, ' ');
    return tmp;
}

char *get_line_map(int max, int before, int after)
{
    char *tmp = "";

    for (int i = 0; i < max - before - after; i++)
        tmp = my_strcat_c(tmp, '-');
    return tmp;
}

void print_color(WINDOW *window, int color, int x, int y)
{
    attron(color);
    mvwaddch(window, y - 9, x + 1, '*');
    attroff(color);
}
