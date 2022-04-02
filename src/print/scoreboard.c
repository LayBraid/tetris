/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"

void print_scoreboard(tetris_t *tetris)
{
    char *tmp = " Level: ";

    my_strcat_3(&tmp, my_itoa(tetris->opt->level));
    wborder(tetris->scoreboard, '|', '|', '-', '-', '/', '\\', '\\', '/');
    refresh();
    mvwprintw(tetris->scoreboard, 1, 1, tmp);
    wrefresh(tetris->scoreboard);
}
