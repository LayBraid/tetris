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
    tmp = " x: ";
    my_strcat_3(&tmp, my_itoa(tetris->next_tetriminos->x));
    my_strcat_3(&tmp, " | y: ");
    my_strcat_3(&tmp, my_itoa(tetris->next_tetriminos->y));
    mvwprintw(tetris->scoreboard, 2, 1, tmp);
    tmp = " [";
    my_strcat_3(&tmp, my_itoa(tetris->next_tetriminos->row));
    my_strcat_3(&tmp, "] [");
    my_strcat_3(&tmp, my_itoa(tetris->next_tetriminos->col));
    my_strcat_3(&tmp, "]");
    mvwprintw(tetris->scoreboard, 3, 1, tmp);
    wrefresh(tetris->scoreboard);
}
