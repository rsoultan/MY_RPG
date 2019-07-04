/*
** EPITECH PROJECT, 2018
** oui
** File description:
** de ouf
*/

#include <stdlib.h>
#include "function.h"

char *my_itoa(unsigned int nb)
{
    char *result;
    unsigned int nb_tmp = nb;
    int size = 0;
    int i = 0;

    if (nb == 0)
        size = 1;
    for (; nb_tmp > 0; size++)
        nb_tmp = nb_tmp / 10;
    result = malloc(sizeof(char) * (size + 1));
    for (; i < size; ++i) {
        nb_tmp = nb;
        nb_tmp = nb_tmp % 10;
        nb = nb / 10;
        result[i] = nb_tmp + '0';
    }
    result[i] = '\0';
    result = my_revstr(result);
    return (result);
}
