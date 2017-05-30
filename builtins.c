/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:42:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/30 13:14:35 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**cmd_init(void)
{
	t_cmd	**tab;
	int		i;

	if (!(tab = (t_cmd **)malloc(sizeof(t_cmd *) * 7)))
	{
		ft_putendl_fd("error: malloc (t_cmd **) has failed", 2);
		exit(1);
	}
	i = 0;
	while (i < 6)
	{
		if (!(tab[i] = (t_cmd *)malloc(sizeof(t_cmd))))
		{
			ft_putendl_fd("error: malloc (t_cmd **) has failed", 2);
			exit(1);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}


void	ft_echo(char **str)
{
	if (!ft_strcmp(*str, "-n"))
	{
		str++;
		while (*str)
		{
			ft_putstr(*str);
			str++;
		}
		return ;
	}
	else
	{
		while (*str)
		{
			ft_putstr(*str);
			str++;
		}
		ft_putchar('\n');
	}
}
