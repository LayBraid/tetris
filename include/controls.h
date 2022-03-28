/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_CONTROLS_H
    #define TETRIS_CONTROLS_H

    #include "tetris.h"

    #define NB_CONTROLS 7
    #define SPACE 32
    #define ENTER 10
    #define ESCAPE 27

typedef struct control_struct {
    int input;
    void (*function)(tetris_t *tetris);
} control_t;

void quit_game(tetris_t *tetris);

#endif
