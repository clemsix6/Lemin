/*
** EPITECH PROJECT, 2022
** Cly
** File description:
** cly_strcmp.c
*/

#include "cly_string.h"
#include <stdlib.h>

int cly_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s1 == *s2) {
        s1 += 1;
        s2 += 1;
    }
    return *s1 - *s2;
}
