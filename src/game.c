/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"
#include "controls.h"
#include "print.h"
#include "tetriminos.h"

static void update_map(tetris_t *tetris)
{
    clear();
    printw("TETRIS GAME");
    refresh();
    print_scoreboard(tetris);
    refresh();
    print_map(tetris);
    refresh();
    if (tetris->opt->next)
        print_next(tetris);
    refresh();
}

static void input_manager(tetris_t *tetris, int input)
{
    for (int i = 0; i < NB_CONTROLS; i++)
        if (input == tetris->controls[i]->input) {
            tetris->controls[i]->function(tetris);
            break;
        }
}

void launch_game(tetris_t *tetris)
{
    get_next_tetriminos(tetris);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    init_controls(tetris);
    tetris->scoreboard = newwin(9, 20, 5, 0);
    tetris->block_game = newwin((tetris->opt->size_row + 2),
    (tetris->opt->size_col + 2), 0, 25);
    tetris->next = newwin(10, 10, 0, tetris->opt->size_col + 30);
    while (tetris->status == PLAYING) {
        update_map(tetris);
        timeout(100);
        input_manager(tetris, getch());
    }
    update_map(tetris);
    endwin();
}
