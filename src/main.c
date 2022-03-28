/*
** EPITECH PROJECT, 2021
** BLANK_PROJECT_C
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "tetris.h"

int print_help(void)
{
    my_putstr("Usage: ./tetris [options]\nOptions:\n");
    my_putstr("  --help               Display this help\n");
    my_putstr("  -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr("  -l --key-left={K}    Move the tetrimino LEFT using the K key"
    " (def: left arrow)\n");
    my_putstr("  -r --key-right={K}   Move the tetrimino RIGHT using the K key"
    " (def: right arrow)\n");
    my_putstr("  -t --key-turn={K}    TURN the tetrimino clockwise 90d using"
    " the K key (def: top arrow)\n");
    my_putstr("  -d --key-drop={K}    DROP the tetrimino using the K key"
    " (def: down arrow)\n");
    my_putstr("  -q --key-quit={K}    QUIT the game using the K key"
    "(def: ‘q’ key)\n");
    my_putstr("  -p --key-pause={K}   PAUSE/RESTART the game using the K key"
    " (def: space bar)\n");
    my_putstr("  --map-size={row,col} Set the numbers of rows and columns of"
    " the map (def: 20,10)\n");
    my_putstr("  -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr("  -D --debug           Debug mode (def: false)\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return print_help();
    return tetris_game(ac, av);
}
