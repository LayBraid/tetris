/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "controls.h"
#include "tetris.h"
#include "utils.h"
#include "tetriminos.h"

void quit_game(tetris_t *tetris)
{
    tetris->status = LOOSE;
}

void drop_tetriminos(tetris_t *tetris)
{
    if (tetris->next_tetriminos->y < tetris->opt->size_row +
        (10 - tetris->next_tetriminos->row) && can_drop(tetris))
        tetris->next_tetriminos->y++;
}

void right_tetriminos(tetris_t *tetris)
{
    if (tetris->next_tetriminos->x < tetris->opt->size_col -
        tetris->next_tetriminos->col)
        tetris->next_tetriminos->x++;
}

void left_tetriminos(tetris_t *tetris)
{
    if (tetris->next_tetriminos->x > 0)
        tetris->next_tetriminos->x--;
}

void rotate_tetriminos(tetris_t *tetris)
{
    rotate_matrix(tetris->next_tetriminos->matrix,
    tetris->next_tetriminos->matrix_size);
    update_design(tetris->next_tetriminos);
}
