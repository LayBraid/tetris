/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#ifndef TETRIS_UTILS_H
    #define TETRIS_UTILS_H

char *get_in_buffer(char *path);

char *extract_between_limits(char const *exp, int s1, int s2);

int get_it_char(const char *str, char c, int index);

int get_curse_key(char *arg);

#endif
