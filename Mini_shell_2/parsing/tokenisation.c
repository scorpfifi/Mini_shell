/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:44:06 by vmpianim          #+#    #+#             */
/*   Updated: 2024/12/06 13:40:11 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

void type_command(t_command *tmp)
{
        if (tmp->token->type == 4)
            tmp->token_type = "herdoc";
        else if (tmp->token->type == 0)
        {
            if (tmp->prev)
            {
                if (tmp->prev->token->type != 0)
                {
                    if (tmp->prev->token->type == 5)
                        tmp->token_type  = "command";
                    else
                        tmp->token_type  = "file";
                }
                else
                    tmp->token_type = "command";
            }
            else
                tmp->token_type = "command";
        }
        else if (tmp->token->type == 3)
            tmp->token_type = "append";
        else if (tmp->token->type == 2)
            tmp->token_type = "redir_out";
        else if (tmp->token->type == 1)
            tmp->token_type = "redir_in";
}


void    pipe_line(t_command *command)
{
    t_command   *tmp;

    tmp = command;
    printf("--------------------PIPELINE----------------------------------\n");
    while (tmp)
    {
        if (tmp->token->type != 5)
            type_command(tmp);
        else
           break;
        tmp = tmp->next;
    }
}

void assing_command(t_command *command)
{
    t_command   *tmp;

    tmp  = command;
    while (tmp)
    {

        if (tmp->token->type == 5)
        {
            tmp->token_type = "Pipe";
            pipe_line(tmp);
        }
        else
            type_command(tmp);
        printf("valu command [%s], type command = [%d], token_type = [%s]\n", (tmp)->token->value, tmp->token->type, tmp->token_type);
       tmp = tmp->next;   
    }
}

int count_token(char *command)
{
    int i;
    int count;
    int in_quotes;

    i = 0;
    count = 0;
    in_quotes = 0;
    while (command[i])
    {
        while (command[i] == ' ')
            i++;
        if (command[i])
            count++;
        while (command[i] && ((command[i] != ' ') || in_quotes))
        {
            if (command[i] == '"' || command[i] == '\'')
                in_quotes = !in_quotes;
            i++;
        }
    }
    return (count);
}



TokenType assing_type(char *command)
{
    TokenType type;
    if (ft_strncmp(command, "<", 1) == 0 && !command[1])
        type = TOKEN_REDIR_IN;
    else if (ft_strncmp(command, ">", 1) == 0 && !command[1])
        type = TOKEN_REDIR_OUT;
    else if (ft_strncmp(command, ">>", 2) == 0)
        type = TOKEN_REDIR_APPEND;
    else if (ft_strncmp(command, "<<", 2) == 0)
        type = TOKEN_REDIR_HERDOC;
    else if (ft_strncmp(command, "|", 1) == 0)
        type = TOKEN_PIPE;
    else
        type = TOKEN_WORD;
    return (type);   
}

t_token *tokenisation(char *command)
{
    TokenType   type;
    t_token     *tokens;
    char        *start;
    int         pos_space;
    int         i;

    tokens = malloc(sizeof(t_token) * (count_token(command) + 1));
    i = 0;
    pos_space = 0;
    start = command;
   tokens->next = NULL;
    while (i < count_token(command))
    {
        tokens[i].id = i;
        pos_space = ft_found_pos(start);
        if (pos_space != 0)
            tokens[i].value = ft_copy_pos(start, pos_space);
        else
            tokens[i].value = ft_copy_pos(start, ft_strlen(start));
        tokens[i].type = assing_type(tokens[i].value);
        tokens[i].value = change_expand(tokens[i].value, 0, 0);
        start = &start[pos_space + 1];
        i++;
    }
    return(tokens);
}
int main(int argc, char **argv)
{
    t_token *token;
    char    *read_line;
    char    *str;
    t_command   *command;

    while (1)
    {
        read_line = readline("bash~ ");
        str = remove_extra_spaces(read_line);
        printf("[%s]\n", str);
        token = tokenisation(str);
        int count = count_token(str);
        command = build_command_list(token, count);
        assing_command(command);
        //print_command_list(command);
        
    }
    
}