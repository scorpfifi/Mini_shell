/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:12:51 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/15 14:03:04 by vmpianim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINI_SHELL
# define MINI_SHELL
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef enum 
{ 
    TOKEN_WORD,  
    TOKEN_REDIR_IN,
    TOKEN_REDIR_OUT,
    TOKEN_REDIR_APPEND,
    TOKEN_REDIR_HERDOC,
    TOKEN_PIPE,
} TokenType;

typedef struct  s_token
{
    int     id;
    int    type;
    char    *value;
    void    *next;
}t_token;

//Tokenisation utils
int ft_found_pos(char *command);
char    *ft_copy_pos(char *src, int pos);
int count_str_cmd(char *command);
char    *clean_command(char *command);
//Tokenisation
int count_token(char *command);
TokenType assing_type(char *command);
t_token *tokenisation(char *command);

#endif
