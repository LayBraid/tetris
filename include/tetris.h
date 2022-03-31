/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_TETRIS_H
    #define TETRIS_TETRIS_H

    #include <getopt.h>
    #include <curses.h>
    #include "struct.h"
    #include <stddef.h>

    #define KEY_LEFT_DEBUG "KEY_LEFT (260)"
    #define KEY_RIGHT_DEBUG "KEY_RIGHT (261)"
    #define KEY_TOP_DEBUG "KEY_TOP (259)"
    #define KEY_BOT_DEBUG "KEY_BOT (258)"

enum GAME {
    PLAYING,
    PAUSE,
    WIN,
    LOOSE,
};

int game(int ac, char **av);

void init_values(tetris_t *tetris);

void launch_game(tetris_t *tetris);

void print_debug(tetris_t *tetris);

#endif
