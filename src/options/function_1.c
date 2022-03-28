/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "options.h"
#include "my.h"
#include "utils.h"

void print_help(tetris_t *tetris)
{
    tetris->opt.help = 1;
    my_putstr("Usage: ./tetris [options]\nOptions:\n  --help               Di"
    "splay this help\n  -L --level={num}     Start Tetris at level num (def: "
    "1)\n  -l --key-left={K}    Move the tetrimino LEFT using the K key (def:"
    " left arrow)\n  -r --key-right={K}   Move the tetrimino RIGHT using the K"
    " key (def: right arrow)\n  -t --key-turn={K}    TURN the tetrimino clock"
    "wise 90d using the K key (def: top arrow)\n  -d --key-drop={K}    DROP "
    "the tetrimino using the K key (def: down arrow)\n  -q --key-quit={K}    "
    "QUIT the game using the K key(def: ‘q’ key)\n  -p --key-pause={K}   "
    "PAUSE/RESTART the game using the K key (def: space bar)\n  --map-size="
    "{row,col} Set the numbers of rows and columns of the map (def: 20,10)\n "
    " -w --without-next    Hide next tetrimino (def: false)\n  -D --debug"
    "           Debug mode (def: false)\n");
}

void set_level(tetris_t *tetris)
{
    tetris->opt.level = my_atoi(tetris->operator_argument);
}

void set_key_left(tetris_t *tetris)
{
    tetris->opt.key_left = get_curse_key(tetris->operator_argument);
}

void set_key_right(tetris_t *tetris)
{
    tetris->opt.key_right = get_curse_key(tetris->operator_argument);
}
