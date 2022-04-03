/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"
#include "tetris.h"

static void check_loose(tetris_t *tetris, int i)
{
    if (tetris->next_tetriminos->y + i <= 10)
        tetris->status = LOOSE;
}

void put_tetriminos(tetris_t *tetris)
{
    for (int i = 0; i < tetris->next_tetriminos->row; i++) {
        for (int j = 0; j < tetris->next_tetriminos->col; j++) {
            check_loose(tetris, i);
            tetris->block[tetris->next_tetriminos->y + i + 1]
            [tetris->next_tetriminos->x + j] =
            (tetris->next_tetriminos->design[i][j] != 0 ?
            tetris->next_tetriminos->design[i][j] :
            tetris->block[tetris->next_tetriminos->y + i + 1]
            [tetris->next_tetriminos->x + j]);
        }
    }
    tetris->opt->level++;
    get_next_tetriminos(tetris);
}
