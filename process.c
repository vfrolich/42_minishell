/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:28:26 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/16 21:43:46 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_checker(t_list *env)
{
	char		*tmp_dir;
	struct stat	stats;

	tmp_dir = NULL;
	if (!(tmp_dir = getcwd(tmp_dir, 256)))
	{
		if (env)
		{
			if ((tmp_dir = get_env_value(env, "OLDPWD")))
			{
				if (stat(tmp_dir, &stats) != -1 && S_ISDIR(stats.st_mode) &&
					access(tmp_dir, X_OK) != -1)
				{
					ft_putendl_fd("minishell: Position undefined, position \
set to OLDPWD", 2);
					chdir(tmp_dir);
					ft_strdel(&tmp_dir);
					return ;
				}
			}
		}
		ft_putendl_fd("minishell: Position undefined, abort.", 2);
		exit(1);
	}
	ft_strdel(&tmp_dir);
}

void	pwd_checker_env(char *pwd, t_list *env)
{
	char		*tmp_dir;
	struct stat stats;

	tmp_dir = NULL;
	if (!(tmp_dir = getcwd(tmp_dir, 256)))
	{
		if ((tmp_dir = get_env_value(env, "OLDPWD")))
		{
			if (stat(tmp_dir, &stats) != -1 && S_ISDIR(stats.st_mode) &&
				access(tmp_dir, X_OK) != -1)
			{
				ft_putendl_fd("minishell: Position undefined, \
position set to OLDPWD", 2);
				chdir(tmp_dir);
			}
		}
		else
		{
			ft_putendl_fd("minishell: Position undefined, abort.", 2);
			exit(1);
		}
	}
	else if (ft_strcmp(pwd, tmp_dir))
		chdir(pwd);
	ft_strdel(&tmp_dir);
}

int		process_manager(char *path, char **arg, char **env)
{
	pid_t	father;
	int		status;

	status = 0;
	father = fork();
	if (father == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, arg, env);
	}
	if (father > 0)
		wait(&status);
	free_tab(arg);
	free_tab(env);
	ft_strdel(&path);
	return (status);
}
