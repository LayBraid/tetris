/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "controls.h"
#include "my.h"

control_t *setup_control(int input, void (* function)(tetris_t *tetris))
{
    control_t *tmp = malloc(sizeof(control_t));

    tmp->input = input;
    tmp->function = function;
    return tmp;
}

void init_controls(tetris_t *tetris)
{
    tetris->controls = malloc(sizeof(control_t *) * NB_CONTROLS);
    tetris->controls[0] = setup_control(tetris->opt->key_quit, quit_game);
    tetris->controls[1] = setup_control(tetris->opt->key_pause, quit_game);
    tetris->controls[2] = setup_control(tetris->opt->key_turn, quit_game);
    tetris->controls[3] = setup_control(tetris->opt->key_drop, quit_game);
    tetris->controls[4] = setup_control(tetris->opt->key_left, quit_game);
    tetris->controls[5] = setup_control(tetris->opt->key_right, quit_game);
}
