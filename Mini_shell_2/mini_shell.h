/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmpianim <vmpianim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:12:51 by vmpianim          #+#    #+#             */
/*   Updated: 2024/11/20 14:46:49 by vmpianim         ###   ########.fr       */
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
    struct s_token  *next;
}t_token;

typedef struct s_command
{
    struct s_command    *next;
    struct s_command    *prev;
    t_token             *token;    
}t_command;

//Tokenisation utils
int ft_found_pos(char *command);
char    *ft_copy_pos(char *src, int pos);
int count_str_cmd(char *command);
char    *clean_command(char *command);
//Tokenisation
int count_token(char *command);
TokenType assing_type(char *command);
t_token *tokenisation(char *command);
//add_command
// void        ft_add_back(t_command **command, t_command *new_command);
// t_command   *new_command(t_token *token);
// t_command   **add_command(t_token *token);
// void        print_command(t_command *command);
t_command *create_command(t_token *token);
void add_command(t_command **head, t_command *new_command);
t_command *build_command_list(t_token *tokens, int token_count);
void print_command_list(t_command *cmd_list);
#endif
