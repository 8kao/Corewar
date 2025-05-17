/*
** EPITECH PROJECT, 2025
** delivery
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"

int is_a_delimiter(char str, const char *reject)
{
    for (int j = 0; reject[j]; j++) {
        if (str == reject[j])
            return 1;
    }
    return 0;
}

int count_words(const char *str, const char *reject)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_a_delimiter(str[i], reject) == 0 && in_word == 0) {
            count++;
            in_word = 1;
        }
        if (is_a_delimiter(str[i], reject) == 1)
            in_word = 0;
    }
    return count;
}

int *count_char_in_words(const char *str, int len, const char *reject)
{
    int char_counter = 0;
    int *lengths = malloc(sizeof(int) * len);
    int j = 0;

    if (!lengths)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_a_delimiter(str[i], reject) == 0) {
                char_counter++;
        }
        if (is_a_delimiter(str[i], reject) == 1 && char_counter > 0) {
            lengths[j] = char_counter;
            char_counter = 0;
            j++;
        }
    }
    if (char_counter > 0)
        lengths[j] = char_counter;
    return lengths;
}

char **put_str_in_array(const char *str, char **array, int len,
    const char *reject)
{
    int x = 0;
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_a_delimiter(str[i], reject) == 0) {
            array[x][y] = str[i];
            y++;
        }
        if (is_a_delimiter(str[i], reject) == 1 & y > 0) {
            array[x][y] = '\0';
            x++;
            y = 0;
        }
    }
    if (y > 0)
        array[x][y] = '\0';
    array[len] = NULL;
    return array;
}

char **my_str_to_word_array(const char *str, const char *reject)
{
    int len = count_words(str, reject);
    int *words_length = count_char_in_words(str, len, reject);
    char **array = malloc(sizeof(char *) * (len + 1));
    int i = 0;

    if (!array || !words_length) {
        free(words_length);
        free(array);
        return NULL;
    }
    while (i < len) {
        array[i] = malloc(sizeof(char) * (words_length[i] + 1));
        i++;
    }
    array[i] = NULL;
    put_str_in_array(str, array, len, reject);
    free(words_length);
    return array;
}
