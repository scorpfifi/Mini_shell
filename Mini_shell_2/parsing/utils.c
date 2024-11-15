/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:09:24 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/15 14:32:52 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int is_separtor(char s)
{
    if (s == '<' || s == '>' || s == '|')
        return (1);
    return (0);
}

int count_str_cmd(char *command)
{
    int i;
    int count;
    
    i = 0;
    count = ft_strlen(command);
    while (command[i])
    {
        if (is_separtor(command[i]) && (command[i + 1]))
            count += 2;
        i++;
    }
    return (count);
}

char    *clean_command(char *command)
{
    int     i;
    char    *dest;
    int     j;
    
    dest = malloc(sizeof(char) * count_str_cmd(command) + 1);
    i = 0;
    j = 0;
    while (command[i])
    {
        if (is_separtor(command[i]) && (command[i + 1] != ' '))
        {
            dest[j++] = ' ';
            dest[j++] = command[i++];
            dest[j++] = ' ';
        }
        dest[j] = command[i];
        j++;
        i++;
    }
    dest[j] = '\0';
    return (dest);
}
int ft_found_pos(char *command)
{
    int i;

    i = 0;
    while (command[i] && command[i] == ' ')
        i++;
    while (command[i] && command[i] != ' ')
        i++;
    return (i);
}

char    *ft_copy_pos(char *src, int pos)
{
    char    *dest;
    int     i;
    int     j;
    int     in_quotes;
   
       
    dest = malloc(sizeof(char) * (pos +1));
    i = 0;
    j = 0;
    in_quotes = 0;
    while (src[i] && i < pos)
    {
        if (src[i] == '"' || src[i] == '\'')
            in_quotes = !in_quotes;
        else
            dest[j++] = src[i];
        i++;
    }
    dest[j] = '\0';
    return (dest);
}
