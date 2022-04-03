/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"

void rotate_matrix(int **matrix, int size)
{
    int temp;

    for (int x = 0; x < size / 2; x++) {
        for (int y = x; y < size - x - 1; y++) {
            temp = matrix[x][y];
            matrix[x][y] = matrix[y][size - 1 - x];
            matrix[y][size - 1 - x] = matrix[size - 1 - x][size - 1 - y];
            matrix[size - 1 - x][size - 1 - y] = matrix[size - 1 - y][x];
            matrix[size - 1 - y][x] = temp;
        }
    }
}
