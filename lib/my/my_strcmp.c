/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** my_strcmp
*/

unsigned int my_strlen(char const *str);

int my_strcmp(const char *s1, const char *s2)
{
    int s1_len = my_strlen(s1);
    int s2_len = my_strlen(s2);

    if (!s1 || !s2 || s1_len != s2_len)
        return (0);
    for (int i = 0; i < s1_len && s1[i] != '\n' && s2[i] != '\n'; ++i) {
        if (s1[i] != s2[i]) {
            return (0);
        }
    }
    return (1);
}