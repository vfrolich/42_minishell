/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:39:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/21 14:23:45 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env{

	char		*field;
	char		*value;
}				t_env;

t_list			*env_ex_nihilo();
t_list			*env_init(char **env);
void			env_init_2(char *arg, t_list **env);
char			*get_cdir();
char			*home_handle(t_list	*env);
void			put_prompt(t_list *env);
void			free_env(t_list *env);
void			free_env_one(t_list *env);
void			free_envvar(t_env *envvar);
void			free_tab(char **tab);
void			print_env(t_list *env);
t_env			*get_fields(char *env);
t_list			*get_env(char **env);
void			add_env(char *name, char *value, t_list **lst);
t_list			*add_to_env(char ***arg, t_list *env);
int				ft_env(char **arg, t_list *env);
int				ft_echo(char **str);
int				ft_set_env(char **arg, t_list **env);
t_list			*set_env(char *name, char *value, t_list **env);
int				set_env_err_handle(char *name, char *value, t_list **env);
int				unset_env(char	*name, t_list *env);
int				ft_cd(t_list *env, char	**arg);
char			*get_env_value(t_list *env, char *field);
char			**env_cpy(char **enriron);
char			**lst_to_tab(t_list *env);
char			**get_path(t_list *env);
char			*search_bin(char *path, char *bin);
char			*search_in_paths(t_list *env, char *bin);
int				read_entry(char *line, t_list **env, int ret);
int				process_manager(char *path, char **arg, char **envi);
void			pwd_checker(t_list *env);
void			pwd_checker_env(char *pwd, t_list *env);
int				err_cd_handle(t_list *env, char **arg);
int				go_home(t_list *env);
int				change_dir(t_list *env, char *path);
int				prev_dir(t_list *env);
int				search_for_builtins(char **arg, t_list **env, int ret);
int				clean_exit(char **arg, int ret);
void			clean_cmd(char **arg, t_list *env);
int				command_launch(char *path, char **arg, t_list *env);
int				exec_check(char	*path);
t_env			*envvar_init(char *field, char *value);
t_list			*ft_lstdup(t_list *lst);
void			put_usage_setenv();

#endif
