/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:41:46 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/07 17:52:08 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_entry(char *line)
{
	char	**arg;

	arg = ft_whitespace(line);
	if (!(ft_strlen(*arg)))
	{
		free_tab(arg);
		return (1);
	}
	free_tab(arg);
	return (0);
}

int		read_entry(char *line, t_list *env, int ret)
{
	char	**arg;
	char	*path;

	if (check_entry(line) == 1)
		return (1);
	arg = ft_whitespace(line);
	ret = search_for_builtins(arg, env, ret);
	if (ret == 2)
	{
		path = search_in_paths(env, arg[0]);
		return (command_launch(path, arg, env));
	}
	free_tab(arg);
	return (ret);
}
