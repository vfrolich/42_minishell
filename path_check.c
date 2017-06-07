/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:11:11 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/07 17:50:35 by vfrolich         ###   ########.fr       */
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
		if (!ft_strcmp(((t_env *)env->content)->field, "PATH"))
		{
			dest = ft_strsplit(((t_env *)env->content)->value, ':');
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
	if (!ft_strcmp(bin, ".") || !ft_strcmp(bin, ".."))
		return (NULL);
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

int		exec_check(char *path)
{
	struct stat stats;
	size_t		len;

	len = ft_strlen(path);
	if (stat(path, &stats) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": no such file or directory", 2);
		return (2);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("minishell: permission denied: ", 2);
		ft_putendl_fd(path, 2);
		return (2);
	}
	else if (path[len - 1] == '.' || path[len - 1] == '/')
	{
		ft_putstr_fd("minishell: invalid command path: ", 2);
		ft_putendl_fd(path, 2);
		return (2);
	}
	return (0);
}
