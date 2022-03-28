/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int lenght = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (lenght + my_strlen(src) + 1));

    for (int j = 0; j < dest[j] != '\0'; ++j)
        tmp[j] = dest[j];
    for (i = 0; src[i] != '\0'; i++)
        tmp[lenght + i] = src[i];
    tmp[lenght + i] = '\0';
    return (tmp);
}

void my_strcat_3(char **dest, char const *src)
{
    for (int i = 0; i < my_strlen(src); i++)
        *dest = my_strcat_c(*dest, src[i]);
}
