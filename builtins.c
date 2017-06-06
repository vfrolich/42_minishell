/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/06 18:42:08 by vfrolich         ###   ########.fr       */
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
		return (ft_env(&arg[1], env));
	if (!ft_strcmp(arg[0], "unsetenv"))
		return (unset_env(arg[1], env));
	if (!ft_strcmp(arg[0], "setenv"))
		return (set_env(arg[1], arg[2], env));
	return (2);
}

t_list	*add_to_env(char ***arg, t_list *env)
{
	char	*tmp;
	size_t	size;

	while (**arg && ft_strchr(**arg, '='))
	{
		if (ft_strchr(**arg, '='))
		{
			size = (ft_strchr(**arg, '=') - **arg);
			tmp = ft_strsub(**arg, 0, size);
			set_env(tmp, ft_strchr(**arg, '=') + 1, env);
			ft_strdel(&tmp);
		}
		(*arg)++;
	}
	return (env);
}

int		ft_env(char **arg, t_list *env)
{
	t_list	*tmp_env;

	if (!(*arg))
	{
		print_env(env);
		return (0);
	}
	if (!ft_strcmp(arg[0], "-i"))
	{
		tmp_env = env_ex_nihilo();
		free_env(env);
	}
	else
		tmp_env = env;
	tmp_env = add_to_env(&arg, tmp_env);
	if (!(*arg))
	{
		print_env(tmp_env);
		return (0);
	}
	ft_putendl(*arg);
	return (0);
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
