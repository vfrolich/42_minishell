/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:07:09 by valentinfrolich   #+#    #+#             */
/*   Updated: 2017/06/17 00:20:46 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_checker(t_list *env)
{
	char		*tmp_dir;
	struct stat	stats;

	tmp_dir = NULL;
	if (!(tmp_dir = getcwd(tmp_dir, 256)))
	{
		if (env)
		{
			if ((tmp_dir = get_env_value(env, "OLDPWD")))
			{
				if (stat(tmp_dir, &stats) != -1 && S_ISDIR(stats.st_mode) &&
					access(tmp_dir, X_OK) != -1)
				{
					ft_putendl_fd("minishell: Position undefined, position \
set to OLDPWD", 2);
					chdir(tmp_dir);
					ft_strdel(&tmp_dir);
					return ;
				}
			}
		}
		ft_putendl_fd("minishell: Position undefined, abort.", 2);
		exit(1);
	}
	ft_strdel(&tmp_dir);
}

void	pwd_checker_env(char *pwd, t_list *env)
{
	char		*tmp_dir;
	struct stat stats;

	tmp_dir = NULL;
	if (!(tmp_dir = getcwd(tmp_dir, 256)))
	{
		if ((tmp_dir = get_env_value(env, "OLDPWD")))
		{
			if (stat(tmp_dir, &stats) != -1 && S_ISDIR(stats.st_mode) &&
				access(tmp_dir, X_OK) != -1)
			{
				ft_putendl_fd("minishell: Position undefined, \
position set to OLDPWD", 2);
				chdir(tmp_dir);
			}
		}
		else
		{
			ft_putendl_fd("minishell: Position undefined, abort.", 2);
			exit(1);
		}
	}
	else if (ft_strcmp(pwd, tmp_dir))
		chdir(pwd);
	ft_strdel(&tmp_dir);
}
