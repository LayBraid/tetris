/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "utils.h"
#include "my.h"

int get_curse_key(char *arg)
{
    if (my_strcmp(arg, "(space)") == 0)
        return 32;
    if (my_strcmp(arg, "KEY_TOP") == 0)
        return 259;
    if (my_strcmp(arg, "KEY_BOT") == 0)
        return 258;
    if (my_strcmp(arg, "KEY_LEFT") == 0)
        return 260;
    if (my_strcmp(arg, "KEY_RIGHT") == 0)
        return 261;
    return my_atoi(arg);
}
