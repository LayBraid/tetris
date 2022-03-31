/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include <stddef.h>
#include "tetriminos.h"
#include "utils.h"
#include "my.h"
#include "tetris.h"

static void fill_this(tetriminos_t *tetriminos, char *buffer)
{
    tetriminos->color = my_atoi(extract_between_limits(buffer, 0,
    get_it_char(buffer, ' ', 0)));
    tetriminos->row = my_atoi(extract_between_limits(buffer,
    get_it_char(buffer, ' ', 0), get_it_char(buffer, ' ', 1)));
    tetriminos->col = my_atoi(extract_between_limits(buffer,
    get_it_char(buffer, ' ', 1), get_it_char(buffer, '\n', 0)));
    if (tetriminos->row < 1 && tetriminos->col < 1) {
        tetriminos->valid = FALSE;
        return;
    }
    tetriminos->design = malloc(sizeof(int *) * tetriminos->row);
    for (int i = 0; i < tetriminos->row; i++)
        tetriminos->design[i] = malloc(sizeof(int) * tetriminos->col);
}

void fill_tetriminos(tetris_t *tetris)
{
    tetriminos_t *tmp = tetris->tetriminos;

    while (tmp->next != NULL) {
        fill_this(tmp, get_in_buffer(tmp->path));
        tmp = tmp->next;
    }
    fill_this(tmp, get_in_buffer(tmp->path));
}
