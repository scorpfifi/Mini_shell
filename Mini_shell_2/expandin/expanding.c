/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:47:52 by vmpianim          #+#    #+#             */
/*   Updated: 2024/12/06 12:29:44 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_shell.h"

int find_char(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}
char *get_variable_value(char *name) 
{
    char *value;
    
    value = getenv(name);
    if (value)
        return ft_strdup(value);
    return strdup("");
}

char    *change_expand(char *input, int i, int j)
{
      char  *result;
      char  *var_name;
      char  *var_value;
      int   start;

      result = malloc(ft_strlen(input) * 2 + 1);
      while (input[i])
      {
        if (input[i] == '$' && ft_isalnum(input[i + 1]))
        {
            i++;
            start = i;
            while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
                i++;
            var_name = ft_substr(input, start, i - start);
            var_value = get_variable_value(var_name);
            free (var_name);
            ft_strlcpy(&result[j], var_value, ft_strlen(var_value) + 2);
            j += ft_strlen(var_value);
            free(var_value);
        }
        else
            result[j++] = input[i++];
      }
      result[j] = '\0';
      return (result);
}

