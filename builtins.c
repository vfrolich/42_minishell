/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/24 21:27:58 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**cmd_init()
{
	t_cmd	**tab;
	int 	i;

	if (!(tab = (t_cmd **)malloc(sizeof(t_cmd *) * 7)))
	{
		ft_putendl_fd("error: malloc (t_cmd **) has failed", 2);
		exit (1);
	}
	i = 0;
	while (i < 6)
	{
		if (!(tab[i] = (t_cmd *)malloc(sizeof(t_cmd))))
		{
			ft_putendl_fd("error: malloc (t_cmd **) has failed", 2);
			exit (1);
		}
		i++;
	}
	tab[0]->fptr = &ft_echo;
	tab[i] = NULL;
	return (tab);
}


void	ft_echo(char *str)
{
	ft_putendl(str);
}

