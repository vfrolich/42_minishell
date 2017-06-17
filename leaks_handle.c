/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentinfrolich <valentinfrolich@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:38:49 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/16 23:48:16 by valentinfrolich  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]))
			ft_strdel(&tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void	free_env(t_list *env)
{
	t_list	*tmp;

	while (env)
	{
		tmp = env->next;
		ft_strdel(&(((t_env *)env->content)->field));
		ft_strdel(&(((t_env *)env->content)->value));
		free(env->content);
		free(env);
		env = tmp;
	}
}

void	free_env_one(t_list *env)
{
	ft_strdel(&((t_env *)env->content)->field);
	ft_strdel(&((t_env *)env->content)->value);
	free(env->content);
	free(env);
}
