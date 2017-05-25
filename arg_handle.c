/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:11:11 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/25 13:31:18 by vfrolich         ###   ########.fr       */
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

void	read_entry(char *line, t_list *env)
{
	char	**arg;
	char	*path;
	char	**envi;

	if (!ft_strlen(line))
		return ;
	arg = ft_whitespace(line);
	if (!arg)
		return ;
	if (!ft_strcmp(arg[0], "cd"))
	{
		if (&arg[1])
			ft_cd(env, &arg[1]);
		free_tab(arg);
		return ;
	}
	path = search_in_paths(env, arg[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(arg[0], 2);
		free_tab(arg);
		return ;
	}
	envi = lst_to_tab(env);
	process_manager(path, arg, envi);
	free_tab(arg);
	free_tab(envi);
	ft_strdel(&path);
}
