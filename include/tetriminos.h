/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_TETRIMINOS_H
    #define TETRIS_TETRIMINOS_H

    #include "struct.h"

int open_tetriminos(tetris_t *tetris);

void fill_tetriminos(tetris_t *tetris);

void set_next_tetriminos(tetris_t *tetris);

void put_tetriminos(tetris_t *tetris);

int can_drop(tetris_t *tetris);

void get_next_display(tetris_t *tetris);

#endif
