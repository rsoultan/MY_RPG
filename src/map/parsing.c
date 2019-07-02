/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** parsing.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "function.h"

char **parse_file(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buf[5];
    char *parsed = malloc(sizeof(char) * 1);
    char **ret = NULL;

    if (fd == -1 || !parsed)
        return (NULL);
    parsed[0] = 0;
    while (read(fd, buf, 5) > 0) {
        parsed = my_strcat(parsed, buf);
        if (!parsed)
            return (NULL);
        for (int i = 0; i < 5; ++i)
            buf[i] = 0;
    }
    ret = my_str_to_word_array(parsed, '\n');
    free(parsed);
    close(fd);
    return (ret);
}