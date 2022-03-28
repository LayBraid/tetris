/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"
#include "controls.h"

void update_map(char **map, int lines)
{
    clear();
    for (int i = 0; i != lines; i++)
        mvprintw(i, 0, map[i]);
    refresh();
}

void input_manager(tetris_t *tetris, int input)
{
    //printf("input: %d\n", input);
    //for (int i = 0; i < NB_CONTROLS; i++)
        //if (input == skb->controls[i]->input) {
        //    skb->controls[i]->function(skb);
        //    break;
        //}
}

void launch_game(tetris_t *tetris)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    while (tetris->status == PLAYING) {
        //update_map(skb->map, skb->lines);
        input_manager(tetris, getch());
        //check_victory(skb);
        //check_fail(skb);
    }
    //update_map(skb->map, skb->lines);
    endwin();
}
