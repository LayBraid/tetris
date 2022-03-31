/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_PRINT_H
    #define TETRIS_PRINT_H

    #include "struct.h"

char *get_scoreboard(tetris_t *tetris, int line);

char *get_next(tetris_t *tetris, int line);

void print_line(tetris_t *tetris, int line);

#endif
