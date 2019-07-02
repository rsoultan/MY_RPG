/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** clean_str
*/

#include <stdlib.h>

static int get_beginning_index(char *str, int *i)
{
    int j = 0;

    if (!str)
        return (-1);
    while (str[*i] == ' ' || str[*i] == '\t')
        *i += 1;
    j = *i;
    while (str[j] != '\0')
        ++j;
    return (j);
}

char *clean_str(char *str)
{
    char *new;
    int i = 0;
    int j = get_beginning_index(str, &i);

    if (j < 0)
        return (NULL);
    new = malloc(sizeof(char) * (j + 1));
    if (!new)
        return (NULL);
    j = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        new[j] = str[i];
        if (new[j] == '\t')
            new[j] = ' ';
        ++i;
        j++;
    }
    new[j] = '\0';
    free(str);
    return (new);
}