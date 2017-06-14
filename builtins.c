/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/14 21:34:08 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (!ft_strcmp(arg[0], "env"))
		return (ft_env(arg, *env));
	if (!ft_strcmp(arg[0], "unsetenv"))
		return (unset_env(arg[1], *env));
	if (!ft_strcmp(arg[0], "setenv") || !ft_strcmp(arg[0], "export"))
	{
		*env = set_env(arg[1], arg[2], env);
		return (0);
	}
	return (2);
}

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
	if (!(*arg))
	{
		print_env(env);
		return (0);
	}
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
