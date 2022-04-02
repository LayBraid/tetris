/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "game_blocks.h"
#include "utils.h"

void init_block(tetris_t *tetris)
{
    tetris->block = get_memory(sizeof(int *) * (tetris->opt->size_row + 10));
    for (int i = 0; i < (tetris->opt->size_row + 10); i++)
        tetris->block[i] = get_memory(sizeof(int) * tetris->opt->size_col);
    for (int i = 0; i < (tetris->opt->size_row + 10); i++)
        for (int j = 0; j < tetris->opt->size_col; j++)
            tetris->block[i][j] = 0;
}
