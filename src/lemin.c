/*
** EPITECH PROJECT, 2022
** Lem-in
** File description:
** main
*/

#include "lemin.h"

void print_room(info_t *info, int st)
{
    node_t *id = *info->rooms;
    room_t *room;

    while (id != NULL) {
        room = id->value;
        if (room->status == st)
            printf("%s %s", room->name, room->args);
        id = id->next;
    }
}

void print_link(info_t *info)
{
    node_t *id = *info->links;
    link_t *link;

    while (id != NULL) {
        link = id->value;
        printf("%s-%s\n", link->a->name, link->b->name);
        id = id->next;
    }
}

int print_result(info_t *info)
{
    printf("#number_of_ants\n%d\n", info->nb_ants);
    printf("#rooms\n##start\n");
    print_room(info, 1);
    printf("##end\n");
    print_room(info, 2);
    print_room(info, 0);
    printf("#tunnels\n");
    print_link(info);
    return 0;
}

int main(void)
{
    info_t *info = malloc(sizeof(info_t));
    node_t *node1 = NULL;
    node_t *node2 = NULL;
    node_t **rooms = &node1;
    node_t **links = &node2;
    info->rooms = rooms;
    info->links = links;
    info->line_nb = 0;
    info->status = 0;

    if (create(info) != 0)
        return 84;
    print_result(info);
    return 0;
}
