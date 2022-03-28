/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_OPTIONS_H
    #define TETRIS_OPTIONS_H

    #include "struct.h"

void init_options(tetris_t *tetris);

void init_arguments(tetris_t *tetris);

void get_arguments(int ac, char **av, tetris_t *tetris);

void set_level(tetris_t *tetris);

void print_help(tetris_t *tetris);

void set_key_left(tetris_t *tetris);

void set_key_right(tetris_t *tetris);

void set_key_turn(tetris_t *tetris);

void set_key_drop(tetris_t *tetris);

void set_key_quit(tetris_t *tetris);

void set_key_pause(tetris_t *tetris);

void set_map_size(tetris_t *tetris);

void set_next(tetris_t *tetris);

void set_debug(tetris_t *tetris);

#endif
