/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "options.h"
#include "tetris.h"
#include "utils.h"
#include "my.h"

void init_arguments(tetris_t *tetris)
{
    tetris->function[0] = (function_option) {'h', print_help};
    tetris->function[1] = (function_option) {'L', set_level};
    tetris->function[2] = (function_option) {'l', set_key_left};
    tetris->function[3] = (function_option) {'r', set_key_right};
    tetris->function[4] = (function_option) {'t', set_key_turn};
    tetris->function[5] = (function_option) {'d', set_key_drop};
    tetris->function[6] = (function_option) {'q', set_key_quit};
    tetris->function[7] = (function_option) {'p', set_key_pause};
    tetris->function[8] = (function_option) {'m', set_map_size};
    tetris->function[9] = (function_option) {'w', set_next};
    tetris->function[10] = (function_option) {'D', set_debug};
}

void handle_argument(tetris_t *tetris, char *name)
{
    tetris->operator_argument = name;
    for (int i = 0; i < 11; i++) {
        if (tetris->operator == tetris->function[i].flag) {
            tetris->function[i].function(tetris);
            break;
        }
    }
}

void get_value(tetris_t *tetris)
{
    switch (tetris->operator) {
        case 0:
            write(1, "no handle ->", 12);
            my_putchar((char) tetris->operator);
            my_putchar('\n');
            break;
        case '0':
        case '1':
        case '2':
            if (tetris->info_operator[0] != 0 &&
                tetris->info_operator[0] != tetris->info_operator[1])
                write(1, "in multiple args\n", 17);
            tetris->info_operator[0] = tetris->info_operator[1];
            break;
        default:
            handle_argument(tetris, optarg);
            break;
    }
}

void get_arguments(int ac, char **av, tetris_t *tetris)
{
    tetris->info_operator = get_memory(sizeof(int) * 3);
    tetris->info_operator[0] = 0;
    tetris->info_operator[1] = 0;
    tetris->info_operator[2] = 0;
    tetris->status = PLAYING;
    init_options(tetris);
    init_values(tetris);
    init_arguments(tetris);
    while (1) {
        tetris->info_operator[1] = optind ? optind : 1;
        tetris->info_operator[2] = 0;
        tetris->operator = getopt_long(ac, av, "hL:l:r:t:d:q:p:m:wD",
        tetris->long_options, &tetris->info_operator[2]);
        if (tetris->operator == -1)
            break;
        get_value(tetris);
    }
}
