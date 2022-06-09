/*
** EPITECH PROJECT, 2022
** Lem-in
** File description:
** parsing
*/

#include "lemin.h"

int get_command_type(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == ' ')
            count++;
    }
    return count;
}

char *my_getcommands(void)
{
    char *buffer = NULL;
    size_t i = 0;

    if (getline(&buffer, &i, stdin) == -1)
        return NULL;
    buffer[i - 1]= '\0';
    return buffer;
}

int command_handling(info_t *info)
{
    if (get_command_type(info->cmd) > 0) {
        if (parse_room(info->cmd, info->last_status, info->rooms) != 0)
            return -1;
    } else if (info->status == 0 && info->line_nb > 1) {
        if (parse_link(info->cmd, info->links, info->rooms) != 0)
            return -1;
    }
    return 0;
}

int check_status(info_t *info)
{
    info->last_status = info->status;
    if (cly_strcmp(info->cmd, "##start\n") == 0)
        info->status = 1;
    else if (cly_strcmp(info->cmd, "##end\n") == 0)
        info->status = 2;
    else
        info->status = 0;
    if (info->line_nb == 1 && info->status == 0)
        info->nb_ants = cly_atoi(info->cmd);
    return 0;
}

int create(info_t *info)
{
    while(1) {
        info->cmd = my_getcommands();
        if (info->cmd == NULL) {
            break;
        } else if (info->cmd[0] == '#' && info->cmd[1] !=  '#') {
            continue;
        } else {
            info->line_nb++;
            check_status(info);
            if (command_handling(info) != 0)
                return -1;
        }
    }
    return 0;
}
