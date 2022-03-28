/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"

void init_options(tetris_t *tetris)
{
    tetris->long_options[0] = (struct option) {"help", no_argument, 0, 'h'};
    tetris->long_options[1] = (struct option) {"level", required_argument, 0,'L'};
    tetris->long_options[2] = (struct option) {"key-left",     required_argument, 0, 'l'};
    tetris->long_options[3] = (struct option) {"key-right",    required_argument, 0, 'r'};
    tetris->long_options[4] = (struct option) {"key-turn",     required_argument, 0, 't'};
    tetris->long_options[5] = (struct option) {"key-drop",     required_argument, 0, 'd'};
    tetris->long_options[6] = (struct option) {"key-quit",     required_argument, 0, 'q'};
    tetris->long_options[7] = (struct option) {"key-pause",    required_argument, 0, 'p'};
    tetris->long_options[8] = (struct option) {"level", required_argument, 0,'L'};
    tetris->long_options[9] = (struct option) {"without-next", required_argument, 0, 'w'};
    tetris->long_options[10] = (struct option) {"debug",        required_argument, 0, 'D'};
}
