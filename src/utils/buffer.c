/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** No file there , just an epitech header example
*/

#include <sys/stat.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include "my.h"
#include "utils.h"

char *get_in_buffer(char *path)
{
    int fd;
    char *buffer;
    struct stat buf;

    if (stat(path, &buf) == -1)
        return "error";
    buffer = malloc(sizeof(char) * (buf.st_size + 1));
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return "error";
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    close(fd);
    return buffer;
}

int max_length_line(const char *buffer)
{
    int max = 0;
    int tmp = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            max = (tmp > max) ? tmp : max;
            tmp = -1;
        }
        tmp++;
    }
    return max;
}

int max_line(const char *buffer)
{
    int count = 1;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count++;
    return count;
}

char *extract_between_limits(char const *exp, int s1, int s2)
{
    int length = s2 - s1;
    char *result = malloc(sizeof(char) * (length + 2));

    for (int index = 0; index <= length; ++index)
        result[index] = exp[index + s1];
    result[length + 1] = '\0';
    return result;
}

int get_it_char(const char *str, char c, int index)
{
    int it = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && it == index)
            return i;
        if (str[i] == c && it != index)
            it++;
    }
    return -1;
}
