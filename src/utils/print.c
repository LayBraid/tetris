/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

char *get_space(int max, int before, int after)
{
    char *tmp = "";

    for (int i = 0; i < max - before - after; i++)
        tmp = my_strcat_c(tmp, ' ');
    return tmp;
}
