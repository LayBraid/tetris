/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "print.h"
#include "tetris.h"
#include "my.h"
#include "utils.h"

char *get_scoreboard(tetris_t *tetris, int line)
{
    char *tmp = "|";

    if (line == 2)
        return "/------------------\\";
    if (line == 3) {
        my_strcat_3(&tmp, " Score:");
        my_strcat_3(&tmp, get_space(16, 6, my_int_len(tetris->score)));
        my_strcat_3(&tmp, my_itoa(tetris->score));
        my_strcat_3(&tmp, " |");
        return tmp;
    }
    if (line == 5) {
        my_strcat_3(&tmp, " Lines:");
        my_strcat_3(&tmp, get_space(16, 6, my_int_len(tetris->lines_ok)));
        my_strcat_3(&tmp, my_itoa(tetris->lines_ok));
        my_strcat_3(&tmp, " |");
        return tmp;
    }
    if (line == 6) {
        my_strcat_3(&tmp, " Level:");
        my_strcat_3(&tmp, get_space(16, 6, my_int_len(tetris->opt.level)));
        my_strcat_3(&tmp, my_itoa(tetris->opt.level));
        my_strcat_3(&tmp, " |");
        return tmp;
    }
    if (line == 8) {
        my_strcat_3(&tmp, " Time:");
        my_strcat_3(&tmp, get_space(16, 5, 6));
        my_strcat_3(&tmp, "12m31s");
        my_strcat_3(&tmp, " |");
        return tmp;
    }
    if (line == 4 || line == 7)
        return "|                  |";
    if (line == 9)
        return "\\------------------/";
    return "                    ";
}
