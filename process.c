/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:28:26 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/01 15:10:06 by vfrolich         ###   ########.fr       */
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
		execve(path, arg, env);
	if (father > 0)
		wait(&status);
	free_tab(arg);
	free_tab(env);
	ft_strdel(&path);
	return (status);
}
