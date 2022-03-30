/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_STRUCT_H
    #define TETRIS_STRUCT_H

typedef struct tetris_game tetris_t;

typedef struct tetriminos_struct {
    char *path;
    int **design;
    int color;
    struct tetriminos_struct *next;
} tetriminos_t;

typedef struct tetris_function_option {
    char flag;
    void (* function)(tetris_t *tetris);
} function_option;

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

struct tetris_game {
    int status;
    int operator;
    char *operator_argument;
    int *info_operator;
    struct option *long_options;
    function_option function[11];
    option_t opt;
    tetriminos_t *tetriminos;
};

#endif
