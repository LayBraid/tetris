/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "options.h"
#include "tetris.h"
#include "tetriminos.h"

int tetris_game(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    tetris->tetriminos = NULL;
    get_arguments(ac, av, tetris);
    open_tetriminos(tetris);
    if (tetris->opt.debug)
        print_debug(tetris);
    if (!tetris->opt.help && !tetris->opt.debug)
        launch_game(tetris);
    return 0;
}
