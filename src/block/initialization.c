/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "game_blocks.h"
#include "my.h"

void init_block(tetris_t *tetris)
{
    tetris->block = malloc(sizeof(int *) * tetris->opt->size_row);
    for (int i = 0; i < tetris->opt->size_row; i++)
        tetris->block[i] = malloc(sizeof(int) * tetris->opt->size_col);
    for (int i = 0; i < tetris->opt->size_row; i++)
        for (int j = 0; j < tetris->opt->size_col; j++)
            tetris->block[i][j] = 0;
}
