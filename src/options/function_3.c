/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "options.h"
#include "tetris.h"

void set_next(tetris_t *tetris)
{
    tetris->opt->next = 0;
}

void set_debug(tetris_t *tetris)
{
    tetris->opt->debug = 1;
}
