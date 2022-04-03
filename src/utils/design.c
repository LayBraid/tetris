/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

static int check_horizon(int size, const int *line)
{
    int count = 0;

    for (int i = 0; i < size; i++)
        if (line[i] != 0)
            count++;
    if (count == 0)
        return 1;
    return 0;
}

static int check_vertical(int size, int **array, int column)
{
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i][column] != 0)
            count++;
    }
    if (count == 0)
        return 1;
    return 0;
}

static void update_horizon(info_t *next, int *info)
{
    for (int i = 0; i < next->matrix_size; i++) {
        info[4] = 0;
        info[4] = check_horizon(next->matrix_size, next->matrix[i]);
        if (info[4] == 0)
            break;
        info[0] += info[4];
    }
    for (int i = next->matrix_size - 1; i > 0; i--) {
        info[4] = 0;
        info[4] = check_horizon(next->matrix_size, next->matrix[i]);
        if (info[4] == 0)
            break;
        info[1] += info[4];
    }
}

static void update_vertical(info_t *next, int *info)
{
    for (int i = 0; i < next->matrix_size; i++) {
        info[4] = 0;
        info[4] = check_vertical(next->matrix_size, next->matrix, i);
        if (info[4] == 0)
            break;
        info[2] += info[4];
    }
    for (int i = next->matrix_size - 1; i > 0; i--) {
        info[4] = 0;
        info[4] = check_vertical(next->matrix_size, next->matrix, i);
        if (info[4] == 0)
            break;
        info[3] += info[4];
    }
}

void update_design(info_t *next)
{
    int info[5] = {0};
    int pos[2] = {0};

    update_horizon(next, info);
    update_vertical(next, info);
    next->row = next->matrix_size - info[1] - info[0];
    next->col = next->matrix_size - info[3] - info[2];
    next->design = NULL;
    next->design = malloc(sizeof(int *) * next->row);
    for (int i = 0; i < next->row; i++)
        next->design[i] = malloc(sizeof(int) * next->col);
    for (int i = 0; i < next->row; i++)
        for (int j = 0; j < next->col; j++)
            next->design[i][j] = 0;
    for (int i = info[0]; i < next->matrix_size - info[1]; i++, pos[0]++) {
        for (int j = info[2]; j < next->matrix_size - info[3]; j++, pos[1]++)
            next->design[pos[0]][pos[1]] = next->matrix[i][j];
        pos[1] = 0;
    }
}
