/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** free_array.c
*/

#include <stdlib.h>

void free_array(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i] != (void *)0; ++i)
        if (arr[i])
            free(arr[i]);
    free(arr);
}