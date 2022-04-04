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
#include "game_blocks.h"

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
    if (tetris->status == PAUSE && input != tetris->opt->key_pause)
        return;
    if (input != tetris->opt->key_drop)
        drop_tetriminos(tetris);
    for (int i = 0; i < NB_CONTROLS; i++)
        if (input == tetris->controls[i]->input) {
            tetris->controls[i]->function(tetris);
            break;
        }
}

void launch_game(tetris_t *tetris)
{
    get_next_display(tetris);
    set_next_tetriminos(tetris);
    get_next_display(tetris);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    init_controls(tetris);
    tetris->scoreboard = newwin(9, 20, 5, 0);
    tetris->block_game = newwin((tetris->opt->size_row + 2),
    (tetris->opt->size_col + 2), 0, 25);
    tetris->next = newwin(10, 10, 0, tetris->opt->size_col + 30);
    while (tetris->status == PLAYING || tetris->status == PAUSE) {
        timeout(200);
        if (tetris->status == PAUSE) {
            input_manager(tetris, getch());
            continue;
        }
        update_map(tetris);
        input_manager(tetris, getch());
        check_full_line(tetris);
    }
    update_map(tetris);
    endwin();
}
