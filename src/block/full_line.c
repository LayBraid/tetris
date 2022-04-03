/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "game_blocks.h"

static void update_this(tetris_t *tetris, int i, int j)
{
    if (tetris->block[i - 1][j] > 0) {
        tetris->block[i][j] = tetris->block[i - 1][j];
        tetris->block[i - 1][j] = 0;
    }
}

static void drop_line(tetris_t *tetris, int line)
{
    tetris->lines_ok++;
    tetris->opt->level++;
    for (int i = 0; i < tetris->opt->size_col; i++)
        tetris->block[line][i] = 0;
    for (int i = line; i > 10; i--)
        for (int j = 0; j < tetris->opt->size_col; j++)
            update_this(tetris, i, j);
}

static int complete_line(tetris_t *tetris, int line)
{
    for (int i = 0; i < tetris->opt->size_col; i++)
        if (tetris->block[line][i] == 0)
            return 0;
    return 1;
}

void check_full_line(tetris_t *tetris)
{
    for (int i = tetris->opt->size_row + 9; i > 10; i--)
        if (complete_line(tetris, i)) {
            drop_line(tetris, i);
            check_full_line(tetris);
            return;
        }
}
