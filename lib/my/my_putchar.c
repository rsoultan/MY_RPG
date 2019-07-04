/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** copy a string
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}