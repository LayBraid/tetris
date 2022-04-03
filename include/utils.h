/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_UTILS_H
    #define TETRIS_UTILS_H

    #include "struct.h"
    #include "stddef.h"

char *get_in_buffer(char *path);

char *extract_between_limits(char const *exp, int s1, int s2);

int get_it_char(const char *str, char c, int index);

int get_curse_key(char *arg);

int max_length_line(const char *buffer);

int max_line(const char *buffer);

int count_tetriminos(tetris_t *tetris);

char *get_space(int max, int before, int after);

char *get_line_map(int max, int before, int after);

char *get_line_block(tetris_t *tetris, int line);

void print_color(WINDOW *window, int color, int x, int y);

void rotate_matrix(int **matrix, int size);

void update_design(info_t *next);

void print_design_this(tetriminos_t *tetriminos, int i, int j);

#endif
