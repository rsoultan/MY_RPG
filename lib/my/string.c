/*
** EPITECH PROJECT, 2018
** MUL_my_rpg_2018
** File description:
** string.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return (0);
    for (len = 0; str[len] != 0; len++);
    return (len);
}

char *my_strcat(char *dest, char *src)
{
    unsigned int len_src = my_strlen(src);
    unsigned int len_dest = my_strlen(dest);
    char *ret = NULL;

    if (!src || !dest)
        return (NULL);
    ret = malloc(sizeof(char) * (len_src + len_dest + 1));
    if (!ret)
        return (NULL);
    ret[len_src + len_dest] = 0;
    for (unsigned int i = 0; i < len_dest; ++i)
        ret[i] = dest[i];
    for (unsigned int i = 0; i < len_src; ++i)
        ret[i + len_dest] = src[i];
    free(dest);
    return (ret);
}