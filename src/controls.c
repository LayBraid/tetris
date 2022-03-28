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
    /*tetris->controls = malloc(sizeof(control_t *) * NB_CONTROLS);
    tetris->controls[0] = setup_control(ENTER, quit_game);
    tetris->controls[1] = setup_control(ESCAPE, quit_game);
    tetris->controls[2] = setup_control(SPACE, quit_game);
    tetris->controls[3] = setup_control(KEY_UP, quit_game);
    tetris->controls[4] = setup_control(KEY_DOWN, quit_game);
    tetris->controls[5] = setup_control(KEY_LEFT, quit_game);
    tetris->controls[6] = setup_control(KEY_RIGHT, quit_game);*/
}
