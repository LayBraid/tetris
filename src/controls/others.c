/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** No file there , just an epitech header example
*/

#include "controls.h"
#include "tetris.h"
#include "tetriminos.h"

void pause_game(tetris_t *tetris)
{
    if (tetris->status == PAUSE)
        tetris->status = PLAYING;
    else
        tetris->status = PAUSE;
}
