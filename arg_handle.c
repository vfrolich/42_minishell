/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:11:11 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/01 18:15:27 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(t_list *env)
{
	t_list	*tmp;
	char	**dest;

	tmp = env;
	while (env)
	{
		if (!ft_strcmp(FIELD, "PATH"))
		{
			dest = ft_strsplit(VALUE, ':');
			env = tmp;
			return (dest);
		}
		env = env->next;
	}
	env = tmp;
	return (NULL);
}

char	*search_bin(char *path, char *bin)
{
	DIR				*dirptr;
	struct dirent	*dir;
	char			*tmp;

	if (!(dirptr = opendir(path)))
		return (NULL);
	while ((dir = readdir(dirptr)))
	{
		if (!ft_strcmp(dir->d_name, bin))
		{
			closedir(dirptr);
			tmp = ft_strjoin(path, "/");
			tmp = ft_strjoin_free_one(&tmp, bin);
			return (tmp);
		}
	}
	closedir(dirptr);
	return (NULL);
}

char	*search_in_paths(t_list *env, char *bin)
{
	char	**paths;
	char	*dest;
	int		i;

	dest = NULL;
	i = 0;
	if (!(paths = get_path(env)))
		return (NULL);
	while (paths[i])
	{
		dest = search_bin(paths[i], bin);
		if (dest)
		{
			free_tab(paths);
			return (dest);
		}
		i++;
	}
	free_tab(paths);
	return (NULL);
}

int		read_entry(char *line, t_list *env)
{
	char	**arg;
	char	*path;
	int		i;

	if (!ft_strlen(line))
		return (0);
	arg = ft_whitespace(line);
	if (!arg)
		return (0);
	i = search_for_builtins(arg, env);
	if (i == -1)
		return (clean_exit(line, arg, env));
	if (!i)
	{
		free_tab(arg);
		return (i);
	}
	path = search_in_paths(env, arg[0]);
	return (command_launch(path, arg, env));
}
