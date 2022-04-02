/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "utils.h"

static void print_this(tetris_t *tetris, int i, int j)
{
    if (tetris->block[i][j] != 0)
        print_color(tetris->block_game, tetris->block[i][j] - 10, j, i);
    else
        mvwprintw(tetris->block_game, i - 9, j + 1, " ");
}

static void print_next_check(tetris_t *tetris, int i, int j)
{
    if (tetris->next_tetriminos->design[i][j] != 0)
        mvwprintw(tetris->block_game, i - 9 + tetris->next_tetriminos->y, j +
        1 + tetris->next_tetriminos->x, "*");
    else
        mvwprintw(tetris->block_game, i - 9 + tetris->next_tetriminos->y, j +
        1 + tetris->next_tetriminos->x, " ");
}

void print_map(tetris_t *tetris)
{
    for (int i = 0; i < tetris->opt->size_row + 10; i++)
        for (int j = 0; j < tetris->opt->size_col; j++)
            print_this(tetris, i, j);
    for (int i = 0; i < tetris->next_tetriminos->row; i++)
        for (int j = 0; j < tetris->next_tetriminos->col; j++)
            print_next_check(tetris, i, j);
    refresh();
    wborder(tetris->block_game, '|', '|', '-', '-', '/', '\\', '\\', '/');
    wrefresh(tetris->block_game);
}
