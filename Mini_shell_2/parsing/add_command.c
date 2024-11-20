/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:15:48 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/20 15:01:50 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

// void    ft_add_back(t_command **command, t_command *new_command)
// {
//     t_command   *temp;
    
//     if (*command == NULL)
//         *command = new_command;
//     else
//     {
//         temp = *command;
//         while (temp->next != NULL)
//             temp = temp->next;
//         temp->next = new_command;
//     }   
// }
// t_command   *new_command(t_token *token)
// {
//     t_command   *new_command;
    
//     new_command = malloc(sizeof(t_command));
//     if (!new_command)
//         return (NULL);
//     new_command->token = token;
//     new_command->next = NULL;
//     return (new_command);
// }
// t_command   **add_command(t_token *token)
// {
//     char        *value;
//     int         i;
//     t_command   **command;
    
//     command = malloc(sizeof(t_command));
//     if (!command)
//         return (NULL);
//     *command = NULL;
//     while (token)
//     {
//         value = token->value;
//         ft_add_back(command, new_command(token));
//         token = token->next;
//     }
//     return(command);
// }

// void    print_command(t_command *command)
// {
//     while (command)
//     {
//         printf("valeur char = %s\n", command->token->value);
//         command = command->next;
//     }
    
// }

t_command *create_command(t_token *token) {
    t_command *cmd = malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->token = token;
    cmd->next = NULL;
    cmd->prev = NULL;
    return cmd;
}

void add_command(t_command **head, t_command *new_command) 
{
    t_command *temp;

    if (!*head) 
    {
        *head = new_command;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_command;
    new_command->prev = temp;
}

t_command *build_command_list(t_token *tokens, int token_count)
{
    t_command *cmd_list = NULL;
    t_command *current_cmd = NULL;
    t_token    *tokens_temp;
    int         count;
    int     i;

    tokens_temp = tokens;
    i = 0;
    while (token_count > 0)
    {
        current_cmd = create_command(&tokens_temp[i]);
        add_command(&cmd_list, current_cmd);
        token_count--;
        i++;
    }
    return (cmd_list);
}


void print_command_list(t_command *command)
{
    t_command   *tmp;

    tmp = (command);
    while (tmp)
    {
        printf("1");
        printf("valu command [%s]\n", (tmp)->token->value);
        tmp = tmp->next;
    }
}
// Libérer la mémoire de la liste de commandes
void free_command_list(t_command *cmd_list)
{
    t_command *current = cmd_list;
    t_command *temp;
    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
}