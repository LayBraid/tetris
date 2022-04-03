/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"

void print_next(tetris_t *tetris)
{
    tetris->next = newwin(tetris->next_display->row + 4,
    tetris->next_display->col + 4, 0, tetris->opt->size_col + 30);
    for (int i = 0; i < tetris->next_display->row; i++)
        for (int j = 0; j < tetris->next_display->col; j++)
            mvwprintw(tetris->next, i + 2, j + 2,
            (tetris->next_display->design[i][j] == 1 ? "*" : " "));
    wborder(tetris->next, '|', '|', '-', '-', '/', '\\', '\\', '/');
    refresh();
    wrefresh(tetris->next);
}
