/*
** EPITECH PROJECT, 2018
** solver
** File description:
** print_array.c
*/

#include "function.h"

void print_array(char **arr, char end_line)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; ++i) {
        my_putstr(arr[i]);
        my_putchar(end_line);
    }
}