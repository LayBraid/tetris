/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"

char *get_next(tetris_t *tetris, int line)
{
    char *tmp = "|";

    if (tetris->opt->next == 0)
        return "";
    if (line == 1)
        return "/-next---\\";
    if (line > 1 && line < 6)
        return "|        |";
    if (line == 6)
        return "\\--------/";
    return "";
}
