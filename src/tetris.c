/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include <printf.h>
#include "my.h"
#include "tetris.h"

void handle_argument(tetris_t *tetris, const char *name)
{
    switch (tetris->operator) {
        case 'h':
            print_help();
            break;
    }
}

void get_value(tetris_t *tetris)
{
    switch (tetris->operator) {
        case 0:
            write(1, "no handle ->", 12);
            my_putchar((char) tetris->operator);
            my_putchar('\n');
        case '0':
        case '1':
        case '2':
            if (tetris->info_operator[0] != 0 &&
                tetris->info_operator[0] != tetris->info_operator[1])
                write(1, "in multiple args\n", 17);
            tetris->info_operator[0] = tetris->info_operator[1];
            printf("DEBUG option %c\n", tetris->operator);
            break;
        default:
            handle_argument(tetris, optarg);
            break;
    }
}

int tetris_game(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));
    tetris->info_operator = malloc(sizeof(int) * 3);
    tetris->info_operator[0] = 0;
    tetris->info_operator[1] = 0;
    tetris->info_operator[2] = 0;
    init_options(tetris);
    while (1) {
        tetris->info_operator[1] = optind ? optind : 1;
        tetris->info_operator[2] = 0;
        tetris->operator = getopt_long(ac, av, "hL:l:r:t:d:q:p:w:D:",
        tetris->long_options, &tetris->info_operator[2]);
        if (tetris->operator == -1)
            break;
        get_value(tetris);
    }
    return 0;
}
