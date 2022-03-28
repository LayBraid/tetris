/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include <printf.h>
#include "my.h"
#include "tetris.h"

void get_value(tetris_t *tetris)
{
    switch (tetris->operator) {
        case 0:
            printf("THIS option %s", tetris->long_options[tetris->info_operator[2]].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;
        case '0':
        case '1':
        case '2':
            if (tetris->info_operator[0] != 0 && tetris->info_operator[0] != tetris->info_operator[1])
                printf("digits occur in two different argv-elements.\n");
            tetris->info_operator[0] = tetris->info_operator[1];
            printf("DEBUG option %c\n", tetris->operator);
            break;
        case 'h':
            print_help();
            break;
        case 'l':
            printf("option l with value '%s'\n", optarg);
            break;
        default:
            printf("?? getopt returned character code 0%o ??\n", tetris->operator);
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
