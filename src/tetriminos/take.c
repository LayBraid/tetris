/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"
#include "my.h"

static void set_next_tetriminos(tetris_t *tetris, tetriminos_t *next)
{
    tetris->next_tetriminos = malloc(sizeof(info_t));
    tetris->next_tetriminos->row = next->row;
    tetris->next_tetriminos->col = next->col;
    tetris->next_tetriminos->x = ((tetris->opt->size_col - next->col) / 2);
    tetris->next_tetriminos->y = 10 - next->row;
    tetris->next_tetriminos->design = malloc(sizeof(int *) * next->row);
    for (int i = 0; i < next->row; i++)
        tetris->next_tetriminos->design[i] = malloc(sizeof(int) * next->col);
    for (int i = 0; i < next->row; i++)
        for (int j = 0; j < next->col; j++)
            tetris->next_tetriminos->design[i][j] = next->design[i][j];
}

void get_next_tetriminos(tetris_t *tetris)
{
    int rand = my_rand(1, tetris->count_tetriminos);
    tetriminos_t *tmp = tetris->tetriminos;

    while (rand > 0) {
        tmp = tmp->next;
        rand--;
    }
    if (!tmp->valid) {
        get_next_tetriminos(tetris);
        return;
    }
    set_next_tetriminos(tetris, tmp);
}
