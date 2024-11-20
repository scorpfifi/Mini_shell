/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:09:24 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/20 12:55:16 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int is_separtor(char s)
{
    if (s == '<' || s == '>' || s == '|')
        return (1);
    return (0);
}
int is_double_separator(char *str)
{
    if (ft_strncmp("<<", str, 2) == 0)
        return (1);
    return (0);
}


int strlen_skape_space(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i + 1] != ' ')
            count++;
        i++;
    }
}

char    *skape_space(char *str)
{
    int     i;
    char    *dest;
    int     j;

    i = 0;
    j = 0;
    dest = malloc(sizeof(char) * strlen_skape_space(str) + 1);
    while(str[i])
    {
        while (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        dest[j++] = str[i++];
    }
    dest[j] = '\0';
    return (dest);
}

int count_str_cmd(char *command) 
{
    int count = 0;
    int i = 0;

    while (command[i])
    {
        if (command[i] != ' ')
            count++;
        i++;
    }
    return (count + 2);
}

char    *add_space(char *str)
{
    int     i;
    char    *dest;
    int     j;

    j = 0;
    dest = malloc(sizeof(char) * count_str_cmd(str) + 1);
    i = 0;
    while (str[i])
    {
        if (is_separtor(str[i]) && str[i + 1] != ' ')
        {
            dest[j++] = ' '; 
            dest[j++] = str[i++];
            dest[j++] = ' ';
        }
        dest[j++] = str[i++];
    }
    dest[j] = '\0';
    return (dest);
}


char    *clean_command(char *command)
{
    int     i;
    char    *dest;
    char    *src;
    int     j;
    
    command = skape_space(command);
    return (command);
}


// char    *clean_command(char *command)
// {
//     int     i;
//     char    *dest;
//     int     j;
    
//     dest = malloc(sizeof(char) * count_str_cmd(command) + 1);
//     i = 0;
//     j = 0;
//     while (command[i])
//     {
//         while (command[i] == ' ' && command[i + 1] == ' ')
//              i++;
//         if (is_separtor(command[i]) && command[i + 1])
//         {
//             if (is_separtor(command[i + 1]))
//             {
//                 if (command[i - 1] != ' ')
//                     dest[j] = ' ';
//                 dest[j++] = command[i++];
//             }
//             else
//             {
//                 dest[j] = ' ';
//                 dest[j++] = command[i++];
//             }
//             if (command[i] != ' ')
//                 dest[j] = ' ';
//         }
//         dest[j++] = command[i++];
//     }
//     dest[j] = '\0';
//     printf("[%s]\n", dest);
//     return (dest);
// }


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
