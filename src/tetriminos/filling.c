/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetriminos.h"
#include "utils.h"
#include "my.h"
#include "tetris.h"

static void get_design(tetriminos_t *tetriminos)
{
    int pos[2] = {0};

    tetriminos->design = get_memory(sizeof(int *) * tetriminos->row);
    for (int i = 0; i < tetriminos->row; i++)
        tetriminos->design[i] = get_memory(sizeof(int) * (tetriminos->col));
    for (int i = 0; tetriminos->buffer[i] != '\0'; i++, pos[0]++) {
        if (tetriminos->buffer[i] == '\n') {
            pos[1] ++;
            pos[0] = -1;
            continue;
        }
        tetriminos->design[pos[1]][pos[0]] =
        (tetriminos->buffer[i] != '*' ? 0 : 1);
    }
}

static void fill_this(tetriminos_t *tetriminos, char *buffer)
{
    if (my_strcmp(buffer, "error") == 0) {
        tetriminos->valid = FALSE;
        return;
    }
    tetriminos->col = my_atoi(extract_between_limits(buffer, 0,
    get_it_char(buffer, ' ', 0)));
    tetriminos->row = my_atoi(extract_between_limits(buffer,
    get_it_char(buffer, ' ', 0), get_it_char(buffer, ' ', 1)));
    tetriminos->color = my_atoi(extract_between_limits(buffer,
    get_it_char(buffer, ' ', 1), get_it_char(buffer, '\n', 0)));
    tetriminos->buffer = extract_between_limits(buffer,
    get_it_char(buffer, '\n', 0) + 1,my_strlen(buffer) - 2);
    if (tetriminos->row < 1 && tetriminos->col < 1) {
        tetriminos->valid = FALSE;
        return;
    }
    tetriminos->valid = TRUE;
    get_design(tetriminos);
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
