/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "time.h"

int my_rand(int i, int j)
{
    int n = i - j + 1;
    int remainder = RAND_MAX % n;
    int x;

    srand(time(NULL));
    x = rand();
    while (x >= RAND_MAX - remainder)
        x = rand();
    return i + x % n;
}
