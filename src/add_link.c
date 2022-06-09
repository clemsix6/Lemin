/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** add_link.c
*/

#include "lemin.h"

room_t *get_room(char *name, node_t **rooms)
{
    node_t *loop_node = *rooms;
    room_t *room;

    while (loop_node != NULL) {
        room = loop_node->value;
        if (cly_strcmp(name, room->name) == 0)
            return room;
        loop_node = loop_node->next;
    }
    return NULL;
}

void add_link(room_t **r, node_t **links)
{
    link_t *link = malloc(sizeof(link_t));
    link->a = r[0];
    link->b = r[1];

    cly_node_push_back(links, link);
}

int parse(char *line, room_t **r, node_t **rooms)
{
    char *second_part = NULL;

    for (int i = 0; line[i] != 0; i++) {
        if (line[i] == '-' && second_part != NULL)
            return -1;
        if (line[i] == '-') {
            line[i] = 0;
            second_part = &(line[i + 1]);
        } else if (line[i] == '\n')
            line[i] = 0;
    }
    if (second_part == NULL)
        return -1;
    r[0] = get_room(line, rooms);
    r[1] = get_room(second_part, rooms);
    return 0;
}

int parse_link(char *line, node_t **links, node_t **rooms)
{
    room_t *r[2];

    if (parse(line, r, rooms) != 0 || r[0] == NULL || r[1] == NULL)
        return -1;
    add_link(r, links);
    return 0;
}
