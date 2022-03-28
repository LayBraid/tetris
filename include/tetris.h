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

enum GAME {
    PLAYING,
    WIN,
    LOOSE,
};

typedef struct tetris_game {
    int status;
    int operator;
    int *info_operator;
    struct option long_options[11];
} tetris_t;

int tetris_game(int ac, char **av);

void init_options(tetris_t *tetris);

int print_help(void);

#endif
