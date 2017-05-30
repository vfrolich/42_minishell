/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:38:49 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/30 15:16:38 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
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

void	free_envvar(t_env *envvar)
{
	ft_strdel(&envvar->field);
	ft_strdel(&envvar->value);
	free(envvar);
	envvar = NULL;
}