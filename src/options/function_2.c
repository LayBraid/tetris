/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "options.h"
#include "tetris.h"
#include "utils.h"
#include "my.h"

void set_key_turn(tetris_t *tetris)
{
    tetris->opt->key_turn = get_curse_key(tetris->operator_argument);
}

void set_key_drop(tetris_t *tetris)
{
    tetris->opt->key_drop = get_curse_key(tetris->operator_argument);
}

void set_key_quit(tetris_t *tetris)
{
    tetris->opt->key_quit = get_curse_key(tetris->operator_argument);
}

void set_key_pause(tetris_t *tetris)
{
    tetris->opt->key_quit = get_curse_key(tetris->operator_argument);
}

void set_map_size(tetris_t *tetris)
{
    if (tetris->opt->size_turn != 1) {
        tetris->opt->size_row = my_atoi(tetris->operator_argument);
        tetris->opt->size_turn = 1;
    } else {
        tetris->opt->size_col = my_atoi(tetris->operator_argument);
    }
}
