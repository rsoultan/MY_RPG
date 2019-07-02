/*
** EPITECH PROJECT, 2018
** atoi
** File description:
** char * to int
*/

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;

    if (str[0] == '-')
        ++i;
    for (; str[i] != '\0'; ++i) {
        nb = nb + str[i] - '0';
        if (str[i + 1] != '\0' && str[i] != '\0')
            nb = nb * 10;
    }
    if (str[0] == '-')
        nb = nb * (-1);
    return (nb);
}
