/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/03 18:01:00 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_for_builtins(char **arg, t_list *env, int ret)
{
	if (!ft_strlen(arg[0]))
		return (2);
	if (!ft_strcmp(arg[0], "exit"))
		exit(clean_exit(arg, ret));
	if (!ft_strcmp(arg[0], "echo"))
		return (ft_echo(&arg[1]));
	if (!ft_strcmp(arg[0], "cd"))
		return (ft_cd(env, &arg[1]));
	if (!ft_strcmp(arg[0], "env"))
	{
		print_env(env);
		return (0);
	}
	if (!ft_strcmp(arg[0], "unsetenv"))
		return (unset_env(arg[1], env));
	if (!ft_strcmp(arg[0], "setenv"))
		return (set_env(arg[1], arg[2], env));
	return (2);
}

int		ft_echo(char **str)
{
	if (!ft_strcmp(*str, "-n"))
	{
		str++;
		while (*str)
		{
			ft_putstr(*str);
			str++;
		}
		return (0);
	}
	if (!ft_strncmp(*str, "-n", 2) && ft_strlen(*str) > 2)
	{
		ft_putendl_fd("usage: echo -n [string]", 2);
		return (1);
	}
	while (*str)
	{
		ft_putstr(*str);
		str++;
		if (*str)
			ft_putchar(32);
	}
	ft_putchar('\n');
	return (0);
}
