/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"

static int check_line(tetris_t *tetris, int i)
{
    for (int j = 0; j < tetris->next_tetriminos->col; j++) {
        if (tetris->next_tetriminos->y + i > tetris->opt->size_row +
            10 - tetris->next_tetriminos->row) {
            put_tetriminos(tetris);
            return 0;
        }
        if (tetris->next_tetriminos->design[i][j] == 1 &&
            tetris->block[tetris->next_tetriminos->y + i + 2]
            [tetris->next_tetriminos->x + j] > 0) {
            put_tetriminos(tetris);
            return 0;
        }
    }
    return 1;
}

int can_drop(tetris_t *tetris)
{
    for (int i = tetris->next_tetriminos->row - 1; i >= 0; i--)
        if (!check_line(tetris, i))
            return 0;
    return 1;
}
