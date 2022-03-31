/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"

void print_line(tetris_t *tetris, int line)
{
    char *tmp = get_scoreboard(tetris, line);
    my_strcat_3(&tmp, get_next(tetris, line));

    mvprintw(line, 0, tmp);
}
