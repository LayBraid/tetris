/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "tetris.h"
#include "my.h"
#include "utils.h"

static int print_this(int input)
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

static void print_this_tetriminos(tetriminos_t *tetriminos)
{
    char *name;

    name = extract_between_limits(tetriminos->path,
    get_it_char(tetriminos->path, '/', 0) + 1,
    get_it_char(tetriminos->path, '.', 0) - 1);
    if (tetriminos->valid == FALSE)
        my_printf("Tetriminos: '%s': error\n", name);
    else {
        my_printf("Tetriminos: '%s': size %d*%d, color %d\n%s\n", name,
        tetriminos->col, tetriminos->row, tetriminos->color,
        tetriminos->buffer);
    }
}

static void print_tetriminos(tetris_t *tetris)
{
    tetriminos_t *tmp = tetris->tetriminos;

    while (tmp->next != NULL) {
        print_this_tetriminos(tmp);
        tmp = tmp->next;
    }
    print_this_tetriminos(tmp);
}

void print_debug(tetris_t *tetris)
{
    my_putstr("Key left: ");
    print_this(tetris->opt->key_left);
    my_putstr("\nKey right: ");
    print_this(tetris->opt->key_right);
    my_putstr("\nKey turn: ");
    print_this(tetris->opt->key_turn);
    my_putstr("\nKey drop: ");
    print_this(tetris->opt->key_drop);
    my_putstr("\nKey quit: ");
    print_this(tetris->opt->key_quit);
    my_putstr("\nKey pause: ");
    print_this(tetris->opt->key_pause);
    if (tetris->opt->next)
        my_putstr("\nNext: Yes");
    else
        my_putstr("\nNext: No");
    my_printf("\nLevel: %d", tetris->opt->level);
    my_printf("\nSize: %d*%d\n", tetris->opt->size_row, tetris->opt->size_col);
    my_printf("\nNumber of tetriminos: %d\n", tetris->count_tetriminos);
    print_tetriminos(tetris);
}
