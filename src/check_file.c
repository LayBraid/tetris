/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "checks.h"
#include "utils.h"
#include "my.h"

int sanity_check(char *path)
{
    char *buffer = get_in_buffer(path);

    if (my_strcmp(buffer, "error") == 0)
        return 84;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (!my_str_contains_c(buffer[i], " \n#XOP"))
            return 84;
    return 1;
}
