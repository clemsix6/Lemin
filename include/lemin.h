/*
** EPITECH PROJECT, 2022
** Lemin
** File description:
** lemin.h
*/

#ifndef BOOTSTRAPLEMIN_BSLEMIN_H
    #define BOOTSTRAPLEMIN_BSLEMIN_H
    #include <stdio.h>
    #include <stdlib.h>
    #include "cly_io.h"
    #include "cly_lib.h"
    #include "cly_string.h"
    #include "cly_linked_list.h"


typedef struct room_s {
    char *name;
    char *args;
    int status;
} room_t;

typedef struct link_s {
    room_t *a;
    room_t *b;
} link_t;

typedef struct info_s {
    int line_nb;
    int status;
    int last_status;
    int nb_ants;
    int room_start;
    int room_end;
    char *cmd;
    char *past_cmd;
    node_t **rooms;
    node_t **links;
} info_t;

int print_result(info_t *info);
int create(info_t *info);
void print_links(node_t **links);
int parse_room(char *line, int status, node_t **rooms);
int parse_link(char *line, node_t **links, node_t **rooms);
void print_links_of(room_t *room, node_t **links);
void print_rooms(node_t **rooms);

#endif //BOOTSTRAPLEMIN_BSLEMIN_H
