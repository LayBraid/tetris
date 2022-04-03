/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"
#include "my.h"

static void set_matrix(tetris_t *tetris)
{
    int max = (tetris->next_display->row > tetris->next_display->col ?
    tetris->next_display->row : tetris->next_display->col);

    tetris->next_tetriminos->matrix_size = max;
    tetris->next_tetriminos->matrix = malloc(sizeof(int *) * max);
    for (int i = 0; i < max; i++)
        tetris->next_tetriminos->matrix[i] = malloc(sizeof(int) * max);
    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++)
            tetris->next_tetriminos->matrix[i][j] = 0;
    for (int i = 0; i < tetris->next_display->row; i++)
        for (int j = 0; j < tetris->next_display->col; j++)
            tetris->next_tetriminos->matrix[i][j] =
            tetris->next_display->design[i][j];
}

void set_next_tetriminos(tetris_t *tetris)
{
    tetris->next_tetriminos = malloc(sizeof(info_t));
    tetris->next_tetriminos->row = tetris->next_display->row;
    tetris->next_tetriminos->col = tetris->next_display->col;
    tetris->next_tetriminos->color = tetris->next_display->color;
    tetris->next_tetriminos->x = tetris->next_display->x;
    tetris->next_tetriminos->y = tetris->next_display->y;
    tetris->next_tetriminos->design =
    malloc(sizeof(int *) * tetris->next_display->row);
    for (int i = 0; i < tetris->next_display->row; i++)
        tetris->next_tetriminos->design[i] =
        malloc(sizeof(int) * tetris->next_display->col);
    for (int i = 0; i < tetris->next_display->row; i++)
        for (int j = 0; j < tetris->next_display->col; j++)
            tetris->next_tetriminos->design[i][j] =
            tetris->next_display->design[i][j];
    set_matrix(tetris);
}
