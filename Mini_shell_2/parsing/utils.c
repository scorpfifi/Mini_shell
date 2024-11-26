/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:09:24 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/26 12:45:40 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int is_separator(char c)
{
    return (c == '<' || c == '>' || c == '|');
}

static void	copy_with_spaces(char *dest, const char *command, int *i, int *j)
{
	if (*j > 0 && dest[*j - 1] != ' ')
		dest[(*j)++] = ' ';
	dest[(*j)++] = command[*i];
	if ((command[*i] == '<' || command[*i] == '>') && command[*i + 1] == command[*i])
		dest[(*j)++] = command[++(*i)];
	if (command[*i + 1] && command[*i + 1] != ' ')
		dest[(*j)++] = ' ';
	(*i)++;
}

char	*clean_command(char *command)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(command) * 3 + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (command[i])
	{
		if (is_separator(command[i]))
			copy_with_spaces(result, command, &i, &j);
		else
			result[j++] = command[i++];
	}
	result[j] = '\0';
	return (result);
}

char	*remove_extra_spaces(const char *str)
{
	char	*result;
	int		i;
	int		j;
	int		was_space;

	result = malloc(strlen(str) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	was_space = 0;
	while (str[i])
	{
		if (isspace(str[i]))
		{
			if (!was_space)
				result[j++] = ' ';
			was_space = 1;
		}
		else
		{
			result[j++] = str[i];
			was_space = 0;
		}
		i++;
	}
	result[j] = '\0';
	return (clean_command(result));
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
