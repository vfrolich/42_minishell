/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/01 18:18:44 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_for_builtins(char **arg, t_list *env)
{
	if (!ft_strlen(arg[0]))
		return (0);
	if (!ft_strcmp(arg[0], "exit"))
		return (-1);
	if (!ft_strcmp(arg[0], "echo"))
		return (ft_echo(&arg[1]));
	if (!ft_strcmp(arg[0], "cd"))
		return (ft_cd(env, &arg[1]));
	if (!ft_strcmp(arg[0], "env"))
	{
		print_env(env);
		return (0);
	}
	return (1);
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
	else
	{
		while (*str)
		{
			ft_putstr(*str);
			str++;
		}
		ft_putchar('\n');
	}
	return (0);
}
