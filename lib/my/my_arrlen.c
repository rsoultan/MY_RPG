/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my_arrlen.c
*/

unsigned int my_arrlen(char **arr)
{
    unsigned int ret = 0;

    if (!arr)
        return (0);
    for (int i = 0; arr[i] != (void *)0; ++i)
        ++ret;
    return (ret);
}