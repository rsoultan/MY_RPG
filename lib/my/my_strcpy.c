/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** my_strcpy
*/

#include <stdlib.h>
#include "../../include/function.h"

char *my_strcpy(char const *src)
{
    char *dest;
    int i = 0;

    if (src == NULL) {
        dest = malloc(sizeof(char) * 1);
        dest[0] = '\0';
    }
    else {
        dest = malloc(sizeof(char) * (my_strlen(src) + 1));
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (dest);
}
