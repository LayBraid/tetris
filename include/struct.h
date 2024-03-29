/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_STRUCT_H
    #define TETRIS_STRUCT_H

    #include "ncurses.h"

typedef struct tetris_game tetris_t;

typedef struct tetriminos_struct {
    char *path;
    char *buffer;
    int valid;
    int **design;
    int color;
    int row;
    int col;
    struct tetriminos_struct *next;
} tetriminos_t;

typedef struct tetris_function_option {
    char flag;
    void (* function)(tetris_t *tetris);
} function_option;

typedef struct control_struct {
    int input;
    void (*function)(tetris_t *tetris);
} control_t;

typedef struct my_option {
    int help;
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int size_row;
    int size_col;
    int size_turn;
    int next;
    int debug;
} option_t;

typedef struct tetriminos_info {
    int **design;
    int color;
    int x;
    int y;
    int row;
    int col;
    int **matrix;
    int matrix_size;
} info_t;

struct tetris_game {
    int status;
    int score;
    int lines_ok;
    int operator;
    char *binary_name;
    char *operator_argument;
    int *info_operator;
    int **block;
    struct option *long_options;
    int count_tetriminos;
    function_option function[11];
    option_t *opt;
    tetriminos_t *tetriminos;
    WINDOW* scoreboard;
    WINDOW* block_game;
    WINDOW* next;
    control_t **controls;
    info_t *next_tetriminos;
    info_t *next_display;
};

#endif
