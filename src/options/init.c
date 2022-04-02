/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"
#include "controls.h"
#include "my.h"

void init_values(tetris_t *tetris)
{
    tetris->opt = malloc(sizeof(option_t));
    tetris->opt->debug = 0;
    tetris->opt->help = 0;
    tetris->opt->level = 1;
    tetris->opt->key_left = KEY_LEFT;
    tetris->opt->key_right = KEY_RIGHT;
    tetris->opt->key_turn = KEY_UP;
    tetris->opt->key_drop = KEY_DOWN;
    tetris->opt->key_quit = 'q';
    tetris->opt->key_pause = SPACE;
    tetris->opt->size_row = 20;
    tetris->opt->size_col = 10;
    tetris->opt->next = 1;
}

void init_options(tetris_t *tetris)
{
    tetris->long_options = malloc(sizeof(struct option) * 11);
    tetris->long_options[0] = (struct option) {"help", 0, 0, 'h'};
    tetris->long_options[1] = (struct option) {"level", 1, 0,'L'};
    tetris->long_options[2] = (struct option) {"key-left", 1, 0, 'l'};
    tetris->long_options[3] = (struct option) {"key-right", 1, 0, 'r'};
    tetris->long_options[4] = (struct option) {"key-turn", 1, 0, 't'};
    tetris->long_options[5] = (struct option) {"key-drop", 1, 0, 'd'};
    tetris->long_options[6] = (struct option) {"key-quit", 1, 0, 'q'};
    tetris->long_options[7] = (struct option) {"key-pause", 1, 0, 'p'};
    tetris->long_options[8] = (struct option) {"map-size", 1, 0,'m'};
    tetris->long_options[9] = (struct option) {"without-next", 1, 0, 'w'};
    tetris->long_options[10] = (struct option) {"debug", 0, 0, 'D'};
}
