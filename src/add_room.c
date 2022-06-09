/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** add_room.c
*/

#include "lemin.h"

int exists(char *name, node_t **rooms)
{
    node_t *loop_node = *rooms;
    room_t *room;

    while (loop_node != NULL) {
        room = loop_node->value;
        if (cly_strcmp(name, room->name) == 0)
            return 1;
        loop_node = loop_node->next;
    }
    return 0;
}

void add_room(char *name, char *args, int status, node_t **rooms)
{
    room_t *room = malloc(sizeof(room_t));

    room->name = name;
    room->status = status;
    room->args = args;
    cly_node_push_back(rooms, room);
}

void clean_args(char *args)
{
    for (int i = 0; args[i] != '\0'; i++) {
        if (args[i] == '#') {
            args[i] = '\n';
            args[i + 1] = 0;
            return;
        }
    }
}

int parse_room(char *line, int status, node_t **rooms)
{
    char *args = NULL;

    for (int i = 0; line[i] != 0; i++) {
        if (line[i] == ' ') {
            line[i] = 0;
            args = &(line[i + 1]);
            break;
        }
    }
    if (exists(line, rooms) != 0)
        return -1;
    clean_args(args);
    add_room(line, args, status, rooms);
    return 0;
}