/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:58:10 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/15 14:10:35 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_fields(char *env)
{
	t_env	*new;
	size_t	size;
	size_t	length;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl_fd("minishell: malloc of t_env * has failed", 2);
		exit(1);
	}
	size = ft_strchr(env, '=') - env;
	if (!(new->field = ft_strsub(env, 0, size)))
	{
		ft_putendl_fd("minishell: malloc of env.field(char *) has failed", 2);
		exit(1);
	}
	length = ft_strlen(ft_strchr(env, '=') + 1);
	size++;
	if (!(new->value = ft_strsub(env, size, length)))
	{
		ft_putendl_fd("minishell: malloc of env.value(char *) has failed", 2);
		exit(1);
	}
	return (new);
}

t_list	*get_env(char **env)
{
	t_list	*start;
	t_list	*new;
	t_env	*new_env;

	new_env = get_fields(*env);
	start = ft_lstnew(new_env, sizeof(t_env));
	free(new_env);
	env++;
	while (*env)
	{
		new_env = get_fields(*env);
		new = ft_lstnew(new_env, sizeof(t_env));
		free(new_env);
		lst_add(new, &start);
		env++;
	}
	return (start);
}

int		unset_env(char *name, t_list *env)
{
	t_list	*tmp;
	t_list	*start;

	start = env;
	if (!name || !env)
		return (1);
	while (env->next)
	{
		if (!(ft_strcmp(((t_env *)env->next->content)->field, name)))
		{
			tmp = env->next;
			env->next = env->next->next;
			free_env_one(tmp);
			env = start;
			return (0);
		}
		env = env->next;
	}
	env = start;
	return (1);
}
