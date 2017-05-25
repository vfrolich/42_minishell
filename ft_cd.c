/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:54:46 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/25 20:16:15 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	go_home(t_list *env)
{
	char	*home;
	char	*old;

	if (!(home = get_env_value(env, "HOME")))
	{
		ft_putendl_fd("cd: HOME isnt defined", 2);
		return ;
	}
	if (access(home, X_OK) == -1)
	{
		ft_putstr_fd("cd: permission denied: ", 2);
		ft_putendl_fd(home, 2);
		return ;
	}
	old = get_cdir();
	chdir(home);
	set_env("OLDPWD", old, 1, env);
	set_env("PWD", home, 1, env);
	ft_strdel(&home);
	ft_strdel(&old);
	return ;
}

void	change_dir(t_list *env, char *path)
{
	char	*old;
	char	*tmp;

	old = get_cdir();
	chdir(path);
	tmp = get_cdir();
	set_env("OLDPWD", old, 1, env);
	set_env("PWD", tmp, 1, env);
	ft_strdel(&tmp);
	ft_strdel(&old);
}

void	err_cd_handle(t_list *env, char **arg)
{
	struct stat stats;

	if (stat(arg[0], &stats) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(arg[0], 2);
	}
	else if (!(S_ISDIR(stats.st_mode)))
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putendl_fd(arg[0], 2);
	}
	else if (arg[0] && arg[1])
		ft_putendl_fd("cd: multiple directory entry", 2);
	else
		change_dir(env, arg[0]);
}

void	ft_cd(t_list *env, char	**arg)
{
	char	*home;
	char	*tmp;

	if (!ft_strlen(arg[0]) || !ft_strcmp(arg[0], "~"))
		go_home(env);
	else
	{
		if (!ft_strncmp(arg[0], "~/", 2))
		{
			if ((home = get_env_value(env, "HOME")))
			{
				tmp = ft_strcut(arg[0], '~');
				ft_strdel(&arg[0]);
				arg[0] = ft_strjoin_free(&home, &tmp);
				err_cd_handle(env, arg);
				return ;
			}
		}
		err_cd_handle(env, arg);
	}
	return ;
}
