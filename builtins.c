/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/21 15:01:15 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*add_to_env(char ***arg, t_list *env)
{
	char	*tmp;
	size_t	size;

	if (!ft_strcmp(*arg[0], "-i"))
	{
		free_env(env);
		env = NULL;
		(*arg)++;
	}
	while (**arg && ft_strchr(**arg, '='))
	{
		if (ft_strchr(**arg, '='))
		{
			size = (ft_strchr(**arg, '=') - **arg);
			tmp = ft_strsub(**arg, 0, size);
			env = set_env(tmp, ft_strchr(**arg, '=') + 1, &env);
			ft_strdel(&tmp);
		}
		(*arg)++;
	}
	return (env);
}

int		ft_env(char **arg, t_list *env)
{
	t_list	*tmp_env;
	int		ret;
	char	*tmp;
	char	**tmp2;

	tmp2 = arg;
	arg++;
	tmp_env = ft_lstdup(env);
	tmp_env = add_to_env(&arg, tmp_env);
	if (!(*arg))
	{
		print_env(tmp_env);
		free_env(tmp_env);
		return (0);
	}
	tmp = ft_wordtab_to_str(arg);
	arg = tmp2;
	ret = read_entry(tmp, &tmp_env, 0);
	ft_strdel(&tmp);
	free_env(tmp_env);
	return (ret);
}

int		ft_echo(char **str)
{
	if (*str && !ft_strcmp(*str, "-n"))
	{
		str++;
		while (*str)
		{
			ft_putstr(*str);
			str++;
		}
		return (0);
	}
	if (*str && !ft_strncmp(*str, "-n", 2) && ft_strlen(*str) > 2)
	{
		ft_putendl_fd("usage: echo [-n] [string]", 2);
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
