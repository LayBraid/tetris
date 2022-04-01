/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"

void print_next(tetris_t *tetris)
{
    wborder(tetris->next, '|', '|', '-', '-', '/', '\\', '\\', '/');
    wrefresh(tetris->next);
}
