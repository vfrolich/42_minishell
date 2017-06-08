/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:38:49 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/08 19:24:45 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]))
			ft_strdel(&tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	free_env(t_list *env)
{
	t_list	*tmp;

	while (env)
	{
		tmp = env->next;
		ft_strdel(&(((t_env *)env->content)->field));
		ft_strdel(&(((t_env *)env->content)->value));
		free(env->content);
		free(env);
		env = tmp;
	}
}

void	free_env_one(t_list *env)
{
	ft_strdel(&((t_env *)env->content)->field);
	ft_strdel(&((t_env *)env->content)->value);
	free(env->content);
	free(env);
}

int		clean_exit(char **arg, int ret)
{
	int tmp;

	if (arg[1] && arg[2])
	{
		ft_putendl_fd("exit: too many arguments", 2);
		return (-1);
	}
	if (arg[1])
	{
		if (ft_strlen(arg[1]) && ft_isnumber(arg[1]))
		{
			tmp = ft_atoi(arg[1]);
			return (tmp);
		}
		ft_putendl_fd("exit: numeric argument required", 2);
		exit(0);
	}
	return (ret);
}
