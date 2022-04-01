/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"
#include "utils.h"

void print_scoreboard(tetris_t *tetris)
{
    wborder(tetris->scoreboard, '|', '|', '-', '-', '/', '\\', '\\', '/');
    refresh();
    wrefresh(tetris->scoreboard);
}
