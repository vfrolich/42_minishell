/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:41:46 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/16 21:44:15 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_for_builtins2(char **arg, t_list **env)
{
	char	*pwd_tmp;
	int		ret;

	if (!ft_strcmp(arg[0], "env"))
	{
		if (!arg[1])
		{
			print_env(*env);
			return (0);
		}
		pwd_tmp = get_cdir(*env);
		ret = ft_env(arg, *env);
		pwd_checker_env(pwd_tmp, *env);
		ft_strdel(&pwd_tmp);
		return (ret);
	}
	if (!ft_strcmp(arg[0], "unsetenv"))
		return (unset_env(arg[1], *env));
	if (!ft_strcmp(arg[0], "setenv") || !ft_strcmp(arg[0], "export"))
		return (ft_set_env(arg, env));
	return (2);
}

int		search_for_builtins(char **arg, t_list **env, int ret)
{
	if (!ft_strlen(arg[0]))
		return (2);
	if (!ft_strcmp(arg[0], "exit"))
	{
		if (clean_exit(arg, ret) != -1)
			exit(clean_exit(arg, ret));
		return (-1);
	}
	if (!ft_strcmp(arg[0], "echo"))
		return (ft_echo(&arg[1]));
	if (!ft_strcmp(arg[0], "cd"))
		return (ft_cd(*env, &arg[1]));
	return (search_for_builtins2(arg, env));
}

int		check_entry(char *line)
{
	char	**arg;

	arg = ft_whitespace(line);
	if (!(ft_strlen(*arg)))
	{
		free_tab(arg);
		return (1);
	}
	free_tab(arg);
	return (0);
}

int		read_entry(char *line, t_list **env, int ret)
{
	char	**arg;
	char	*path;

	if (check_entry(line) == 1)
		return (1);
	arg = ft_whitespace(line);
	ret = search_for_builtins(arg, env, ret);
	if (ret == 2)
	{
		path = search_in_paths(*env, arg[0]);
		return (command_launch(path, arg, *env));
	}
	free_tab(arg);
	return (ret);
}
