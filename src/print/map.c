/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "print.h"
#include "utils.h"

static void print_this(tetris_t *tetris, int i, int j)
{
    if (tetris->block[i][j] != -1)
        print_color(tetris->block_game, tetris->block[i][j], j, i);
    else
        mvwprintw(tetris->block_game, i + 1, j + 1, " ");
}

void print_map(tetris_t *tetris)
{
    wborder(tetris->block_game, '|', '|', '-', '-', '/', '\\', '\\', '/');
    for (int i = 0; i < tetris->opt->size_row; i++)
        for (int j = 0; j < tetris->opt->size_col; j++)
            print_this(tetris, i, j);
    refresh();
    wrefresh(tetris->block_game);
}
