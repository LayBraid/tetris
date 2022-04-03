/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"
#include "my.h"

static void set_matrix(tetris_t *tetris, tetriminos_t *next)
{
    int max = (next->row > next->col ? next->row : next->col);

    tetris->next_display->matrix_size = max;
    tetris->next_display->matrix = malloc(sizeof(int *) * max);
    for (int i = 0; i < max; i++)
        tetris->next_display->matrix[i] = malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            tetris->next_display->matrix[i][j] = 0;
    for (int i = 0; i < next->row; i++)
        for (int j = 0; j < next->col; j++)
            tetris->next_display->matrix[i][j] = next->design[i][j];
}

static void set_next_display(tetris_t *tetris, tetriminos_t *next)
{
    tetris->next_display = malloc(sizeof(info_t));
    tetris->next_display->row = next->row;
    tetris->next_display->col = next->col;
    tetris->next_display->x = ((tetris->opt->size_col - next->col) / 2);
    tetris->next_display->y = 10 - next->row;
    tetris->next_display->design = malloc(sizeof(int *) * next->row);
    for (int i = 0; i < next->row; i++)
        tetris->next_display->design[i] =
                malloc(sizeof(int) * next->col);
    for (int i = 0; i < next->row; i++)
        for (int j = 0; j < next->col; j++)
            tetris->next_display->design[i][j] = next->design[i][j];
    set_matrix(tetris, next);
}

void get_next_display(tetris_t *tetris)
{
    int rand = my_rand(1, tetris->count_tetriminos);
    tetriminos_t *tmp = tetris->tetriminos;

    while (rand > 0) {
        tmp = tmp->next;
        rand--;
    }
    if (!tmp->valid) {
        get_next_display(tetris);
        return;
    }
    set_next_display(tetris, tmp);
}
