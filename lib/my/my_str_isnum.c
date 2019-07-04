/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_isnum
*/

int my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        ++i;
    }
    return (0);
}
