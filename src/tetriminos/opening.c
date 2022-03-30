/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include <dirent.h>
#include <stddef.h>
#include "tetriminos.h"
#include "my.h"

static void add_file_tetriminos(tetris_t *tetris, const char *path)
{
    tetriminos_t *tmp = malloc(sizeof(tetriminos_t));
    tetriminos_t *new = malloc(sizeof(tetriminos_t));

    if (tetris->tetriminos == NULL) {
        tetris->tetriminos = malloc(sizeof(tetriminos_t));
        tetris->tetriminos->path = "tetriminos/";
        my_strcat_3(&tetris->tetriminos->path, path);
        tetris->tetriminos->next = NULL;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        new->path = "tetriminos/";
        my_strcat_3(&new->path, path);
        new->next = NULL;
        tmp->next = new;
    }
}

void open_tetriminos(tetris_t *tetris)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL)
        if (dp->d_name[0] != '.')
            add_file_tetriminos(tetris, dp->d_name);
    closedir(dir);
    free(dir);
    free(dp);
}
