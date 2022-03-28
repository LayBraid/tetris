/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"
#include "my.h"

int print_this(int input)
{
    if (input == 258)
        return my_putstr(KEY_BOT_DEBUG);
    if (input == 259)
        return my_putstr(KEY_TOP_DEBUG);
    if (input == 260)
        return my_putstr(KEY_LEFT_DEBUG);
    if (input == 261)
        return my_putstr(KEY_RIGHT_DEBUG);
    return my_printf("%c (%d)", (char) input, input);
}

void print_debug(tetris_t *tetris)
{
    my_putstr("Key left: ");
    print_this(tetris->opt.key_left);
    my_putstr("\nKey right: ");
    print_this(tetris->opt.key_right);
    my_putstr("\nKey turn: ");
    print_this(tetris->opt.key_turn);
    my_putstr("\nKey drop: ");
    print_this(tetris->opt.key_drop);
    my_putstr("\nKey quit: ");
    print_this(tetris->opt.key_quit);
    my_putstr("\nKey pause: ");
    print_this(tetris->opt.key_pause);
    if (tetris->opt.next)
        my_putstr("\nNext: Yes");
    else
        my_putstr("\nNext: No");
    my_printf("\nLevel: %d", tetris->opt.level);
    my_printf("\nSize: %d*%d\n", tetris->opt.size_row, tetris->opt.size_col);
}
