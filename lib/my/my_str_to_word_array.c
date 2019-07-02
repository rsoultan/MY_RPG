/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** my_str_to_word_array
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *);

static int word_n_len(char *str, int n, char c)
{
    int i = 0;

    for (; str[i + n] != '\0' && str[i + n] != c
        && (str[i + n] != '\\' || str[i + n + 1] != 't')
        && (str[i + n] != 't' || (i + n == 0
        || str[i + n - 1] != '\\')); ++i);
    return (i);
}

static int nb_words(char *str, char c)
{
    int nb_words = 0;
    unsigned int j = 0;

    for (unsigned int i = 0; i < (unsigned int)my_strlen(str); ++i) {
        i += word_n_len(str, i, c);
        if (j != i)
            nb_words++;
        j = i + 1;
    }
    return (nb_words);
}

static char *words_n_copy(char *str, int n, char c)
{
    int len = word_n_len(str, n, c);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (new == NULL)
        return (NULL);
    for (; i < len; ++i)
        new[i] = str[n + i];
    new[i] = '\0';
    return (new);
}

char **my_str_to_word_array(char *str, char c)
{
    unsigned int j = 0;
    int nbwords = -1;
    char **result = malloc(sizeof(char *) * (nb_words(str, c) + 1));

    if (result == NULL)
        return (NULL);
    for (unsigned int i = 0; i < (unsigned int)my_strlen(str); ++i) {
        i += word_n_len(str, i, c);
        if (j != i) {
            nbwords++;
            result[nbwords] = words_n_copy(str, j, c);
        }
        if (nbwords != -1 && result[nbwords] == NULL)
            return (NULL);
        j = i + 1;
    }
    result[nbwords + 1] = NULL;
    return (result);
}