/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** lemin.c
*/

#include "lemin.h"

room_t **get_links(room_t *room, node_t **links)
{
    node_t *null_node = NULL;
    node_t **result = &null_node;
    node_t *next = *links;
    link_t *link;

    while (next != NULL) {
        link = next->value;
        if (link->a == room)
            cly_node_push_back(result, link->b);
        else if (link->b == room)
            cly_node_push_back(result, link->a);
        next = next->next;
    }
    return cly_node_to_array(result);;
}