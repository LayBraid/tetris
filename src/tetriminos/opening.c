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
#include "utils.h"

static void sort_files(tetris_t *tetris)
{
    tetriminos_t *tmp = tetris->tetriminos;
    char *save;

    while (tmp->next->next != NULL) {
        if (my_strcmp(tmp->path, tmp->next->path) > 0) {
            save = tmp->path;
            tmp->path = tmp->next->path;
            tmp->next->path = save;
            sort_files(tetris);
        }
        tmp = tmp->next;
    }
    if (my_strcmp(tmp->path, tmp->next->path) > 0) {
        save = tmp->path;
        tmp->path = tmp->next->path;
        tmp->next->path = save;
        sort_files(tetris);
    }
}

static void add_file_tetriminos(tetris_t *tetris, const char *path)
{
    tetriminos_t *tmp = tetris->tetriminos;
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

int open_tetriminos(tetris_t *tetris)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *dp;
    char *save;

    if (dir == NULL)
        return 84;
    while ((dp = readdir(dir)) != NULL)
        if (dp->d_name[0] != '.')
            add_file_tetriminos(tetris, dp->d_name);
    closedir(dir);

    if (my_strcmp(tetris->tetriminos->path,
        tetris->tetriminos->next->path) > 0) {
        save = tetris->tetriminos->path;
        tetris->tetriminos->path = tetris->tetriminos->next->path;
        tetris->tetriminos->next->path = save;
    }
    sort_files(tetris);
    return 0;
}
