/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_strncmp
*/

int my_strncmp(char *str1,char *str2, int size)
{
    int i = 0;

    while (i < size) {
        if (str1[i] != str2[i])
            return (0);
        ++i;
    }
    return (1);
}