/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:44:06 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/20 15:01:20 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

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
    t_command   **coms;

    tokens = malloc(sizeof(t_token) * (count_token(command) + 1));
    i = 0;
    start = command;
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
        start = &start[pos_space + 1];
        printf ("id = %d, value = %s, type = %d\n", tokens[i].id, tokens[i].value, tokens[i].type);
        i++;
    }
    //tokens->next = NULL;
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
        str = clean_command(read_line);
        token = tokenisation(str);
        int count = count_token(str);
        command = build_command_list(token, count);
        print_command_list(command);
        
    }
    
}