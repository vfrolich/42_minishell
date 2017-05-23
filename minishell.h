/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:39:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/23 18:33:09 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <dirent.h>
# include "libft/libft.h"
# include <sys/wait.h>
# define FIELD ((t_env *)env->content)->field
# define VALUE ((t_env *)env->content)->value

typedef struct	s_env{

	char		*field;
	char		*value;
}				t_env;

void			put_prompt();
void			free_env(t_list *env);
void			free_tab(char **tab);
void			print_env(t_list *env);
t_env			*get_fields(char *env);
t_list			*get_env(char **env);
int				add_env(char *name, char *value, t_list *lst);
int				set_env(char *name, char *value, int overwrite, t_list *env);
int				unset_env(char	*name, t_list *env);
char			**env_cpy(char **enriron);
char			**lst_to_tab(t_list *env);
char			**get_path(t_list *env);
char			*search_bin(char *path, char *bin);
char			*search_in_paths(t_list *env, char *bin);
void			read_entry(char *line, t_list *env);
void			process_manager(char *path,char **arg, char **envi);


#endif
