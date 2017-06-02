/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 22:50:59 by valentinfrolich   #+#    #+#             */
/*   Updated: 2017/06/02 18:56:03 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *env)
{
	t_list	*start;

	start = env;
	while (env)
	{
		ft_putstr(FIELD);
		ft_putstr("=");
		ft_putendl(VALUE);
		env = env->next;
	}
	env = start;
}

char	**env_cpy(char **environ)
{
	int		n;
	char	**tmp;
	char	**dest;

	n = 0;
	tmp = environ;
	while (*tmp++)
		n++;
	dest = (char **)malloc(sizeof(char *) * (n + 1));
	dest[n] = NULL;
	tmp = dest;
	while (*environ++)
	{
		if (*environ)
			*dest = ft_strdup(*environ);
		dest++;
	}
	return (tmp);
}

char	*get_env_value(t_list *env, char *field)
{
	t_list	*tmp;
	char	*dest;

	tmp = env;
	while (env)
	{
		if (!ft_strcmp(field, FIELD))
		{
			dest = ft_strdup(VALUE);
			env = tmp;
			return (dest);
		}
		env = env->next;
	}
	env = tmp;
	return (NULL);
}

char	**lst_to_tab(t_list *env)
{
	char	**dest;
	size_t	len;
	t_list	*tmp;

	tmp = env;
	len = ft_count_lst(tmp);
	if (!(dest = (char **)malloc(sizeof(char *) * (len + 1))))
	{
		ft_putstr_fd("malloc of char ** dest has failed", 2);
		exit(1);
	}
	dest[len] = NULL;
	len = 0;
	while (env)
	{
		dest[len] = ft_strjoin(FIELD, "=");
		dest[len] = ft_strjoin_free_one(&dest[len], VALUE);
		len++;
		env = env->next;
	}
	return (&dest[0]);
}

int		command_launch(char *path, char **arg, t_list *env)
{
	char	**envi;

	if (!path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(arg[0], 2);
		free_tab(arg);
		return (127);
	}
	envi = lst_to_tab(env);
	return (process_manager(path, arg, envi));
}
