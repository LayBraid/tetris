/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_CONTROLS_H
    #define TETRIS_CONTROLS_H

    #include "struct.h"

    #define NB_CONTROLS 6
    #define SPACE 32

void init_controls(tetris_t *tetris);

void quit_game(tetris_t *tetris);

void drop_tetriminos(tetris_t *tetris);

void right_tetriminos(tetris_t *tetris);

void left_tetriminos(tetris_t *tetris);

#endif
