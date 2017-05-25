/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 19:58:10 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/25 15:17:22 by vfrolich         ###   ########.fr       */
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
		ft_putendl_fd("error: malloc of t_env * has failed", 2);
		exit(1);
	}
	size = ft_strchr(env, '=') - env;
	if (!(new->field = ft_strsub(env, 0, size)))
	{
		ft_putendl_fd("error: malloc of env.field(char *) has failed", 2);
		exit(1);
	}
	length = ft_strlen(ft_strchr(env, '=') + 1);
	size++;
	if (!(new->value = ft_strsub(env, size, length)))
	{
		ft_putendl_fd("error: malloc of env.value(char *) has failed", 2);
		exit(1);
	}
	return (new);
}

int		add_env(char *name, char *value, t_list *lst)
{
	t_list	*new;
	t_env	*new_env;

	if (!(new_env = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl_fd("error: malloc of t_env * has failed", 2);
		return (1);
	}
	new_env->field = ft_strdup(name);
	new_env->value = ft_strdup(value);
	if (!(new = ft_lstnew(new_env, sizeof(t_env *))))
	{
		ft_putendl_fd("error: malloc of t_list * has failed", 2);
		return (1);
	}
	lst->next = new;
	return (0);
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

int		set_env(char *name, char *value, int overwrite, t_list *env)
{
	int		flag;
	t_list	*start;

	flag = 0;
	start = env;
	while (env->next)
	{
		if (!(ft_strcmp(FIELD, name)))
		{
			flag = 1;
			if (overwrite)
			{
				if (VALUE)
					ft_strdel(&VALUE);
				VALUE = ft_strdup(value);
			}
		}
		env = env->next;
	}
	if (!flag)
		if (add_env(name, value, env))
			return (-1);
	env = start;
	return (0);
}

int		unset_env(char *name, t_list *env)
{
	int		flag;
	t_list	*tmp;
	t_list	*start;

	flag = 0;
	start = env;
	while (env->next)
	{
		if (!(ft_strcmp(((t_env *)env->next->content)->field, name)))
		{
			flag = 1;
			tmp = env->next;
			env->next = env->next->next;
			free_env(tmp);
			free(tmp);
		}
		env = env->next;
	}
	env = start;
	if (flag)
		return (0);
	return (-1);
}
