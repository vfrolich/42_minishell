/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:25:12 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/29 12:23:55 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_prompt(t_list *env)
{
	char	*pwd;

	ft_putchar('\033');
	ft_putstr("[36m");
	pwd = home_handle(env);
	ft_putstr(pwd);
	ft_putstr("$ ");
	ft_putchar('\033');
	ft_putstr("[39m");
	ft_strdel(&pwd);
}

char	*home_handle(t_list *env)
{
	char	*dir;
	char	*home;
	char	*tmp;
	size_t	size;

	dir = get_cdir();
	if (!(home = get_env_value(env, "HOME")))
		return (dir);
	size = ft_strlen(home);
	if (!ft_strncmp(dir, home, size))
	{
		if (!(tmp = ft_strsub(dir, size, (ft_strlen(dir) - size))))
		{
			ft_putendl_fd("malloc of char * has failed", 2);
			exit(1);
		}
		ft_strdel(&home);
		ft_strdel(&dir);
		ft_putstr("-> ~");
		return (tmp);
	}
	return (dir);
}

char	*get_cdir(t_list *env)
{
	char	*cdir;

	cdir = NULL;
	cdir = getcwd(cdir, 256);
	if (!cdir)
	{
		if ((cdir = get_env_value(env, "OLDPWD")))
			return (cdir);
		ft_putendl_fd("malloc of char * has failed", 2);
		exit(1);
	}
	return (cdir);
}
