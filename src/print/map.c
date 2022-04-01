/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "print.h"
#include "utils.h"

void print_map(tetris_t *tetris)
{
    wborder(tetris->block_game, '|', '|', '-', '-', '/', '\\', '\\', '/');
    wrefresh(tetris->block_game);
}
