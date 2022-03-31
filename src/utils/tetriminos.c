/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"

int count_tetriminos(tetris_t *tetris)
{
    tetriminos_t *tmp = tetris->tetriminos;
    int count = 1;

    if (tetris->tetriminos == NULL)
        return 0;
    while (tmp->next != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
