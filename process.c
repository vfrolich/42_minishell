/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:28:26 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/03 17:09:39 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_manager(char *path, char **arg, char **env)
{
	pid_t	father;
	int		status;

	status = 0;
	father = fork();
	if (father == 0)
	{
		signal(SIGINT, SIG_DFL);
		execve(path, arg, env);
	}
	if (father > 0)
		wait(&status);
	free_tab(arg);
	free_tab(env);
	path ? ft_strdel(&path) : NULL;
	return (status);
}
