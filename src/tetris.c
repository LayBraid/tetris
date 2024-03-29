/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include "options.h"
#include "tetris.h"
#include "tetriminos.h"
#include "utils.h"
#include "game_blocks.h"
#include "my.h"

int game(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    tetris->tetriminos = NULL;
    tetris->score = 0;
    tetris->lines_ok = 0;
    tetris->binary_name = av[0];

    get_arguments(ac, av, tetris);
    if (open_tetriminos(tetris) == 84)
        return 84;
    fill_tetriminos(tetris);
    init_block(tetris);
    tetris->count_tetriminos = count_tetriminos(tetris);
    if (tetris->count_tetriminos == 0)
        return 84;
    if (tetris->opt->debug && !tetris->opt->help)
        print_debug(tetris);
    if (!tetris->opt->help && !tetris->opt->debug)
        launch_game(tetris);
    return 0;
}
