/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "controls.h"

void quit_game(tetris_t *tetris)
{
    tetris->status = LOOSE;
}