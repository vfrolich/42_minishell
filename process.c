/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:28:26 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/17 00:26:51 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

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

int		command_launch(char *path, char **arg, t_list *env)
{
	char	**envi;

	if (!path)
	{
		if (ft_strchr(arg[0], '/'))
		{
			path = ft_strdup(arg[0]);
			if (exec_check(path) == 2)
			{
				free_tab(arg);
				ft_strdel(&path);
				return (127);
			}
			envi = lst_to_tab(env);
			return (process_manager(path, arg, envi));
		}
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(arg[0], 2);
		free_tab(arg);
		return (127);
	}
	envi = lst_to_tab(env);
	return (process_manager(path, arg, envi));
}
