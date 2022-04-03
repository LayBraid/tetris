/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

void print_design_this(tetriminos_t *tetriminos, int i, int j)
{
    int count = 0;

    if (tetriminos->design[i][j] == 1) {
        my_putchar('*');
        return;
    }
    for (int k = j; k < tetriminos->col; k++)
        if (tetriminos->design[i][k] == 1)
            count++;
    if (count > 0)
        my_putchar(' ');
}
