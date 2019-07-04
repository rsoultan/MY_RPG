/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** task03 CPool_Day06_2018
*/

char *my_revstr(char *str)
{
    int i;
    int x;
    int inter;

    x = 0;
    for (i = 0; str[i] != '\0'; ++i);
    for (int y = i; x <i / 2; x++) {
        y--;
        inter = str[x];
        str[x] = str[y];
        str[y] = inter;
    }
    return (str);
}
