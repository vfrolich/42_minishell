/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:09:48 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/15 14:29:37 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_env_err_handle(char *name, char *value, t_list **env)
{
	if (!name && !value)
	{
		print_env(*env);
		return (1);
	}
	if (!value || !name)
	{
		put_usage_setenv();
		return (1);
	}
	if (!(*env))
	{
		add_env(name, value, env);
		return (1);
	}
	return (0);
}

void	add_env(char *name, char *value, t_list **lst)
{
	t_list	*new;
	t_env	*new_env;

	if (!(new_env = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl_fd("minishell: malloc of t_env * has failed", 2);
		exit(1);
	}
	if (!(new = ft_lstnew(new_env, sizeof(t_env *))))
	{
		ft_putendl_fd("minishell: malloc of t_list * has failed", 2);
		exit(1);
	}
	((t_env *)new->content)->field = ft_strdup(name);
	((t_env *)new->content)->value = ft_strdup(value);
	lst_add(new, lst);
	free(new_env);
}

t_list	*set_env(char *name, char *value, t_list **env)
{
	t_list	*start;

	start = *env;
	if (set_env_err_handle(name, value, env))
		return (*env);
	while (start->next)
	{
		if ((!ft_strcmp(((t_env *)start->content)->field, name)))
		{
			ft_strdel(&((t_env *)start->content)->value);
			((t_env *)start->content)->value = ft_strdup(value);
			return (*env);
		}
		start = start->next;
	}
	add_env(name, value, env);
	return (*env);
}
