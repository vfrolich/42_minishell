/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:36:27 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/18 19:41:58 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *env)
{
	t_list	*start;

	start = env;
	while (env)
	{
		ft_putstr("for field : ");
		ft_putstr(((t_env *)env->content)->field);
		ft_putstr(" value is : ");
		ft_putendl(((t_env *)env->content)->value);
		env = env->next;
	}
	env = start;
}

void	free_env(t_list *env)
{
	if (((t_env *)env->content)->field)
		ft_strdel(&(((t_env *)env->content)->field));
	if (((t_env *)env->content)->value)
		ft_strdel(&(((t_env *)env->content)->value));
	free(env->content);
}

char	**env_cpy(char **environ)
{
	int		n;
	char	**tmp;
	char	**dest;

	n = 0;
	tmp = environ;
	while (*tmp++)
		n++;
	dest = (char **)malloc(sizeof(char *) * (n + 1));
	dest[n] = NULL;
	tmp = dest;
	while (*environ++)
	{
		if (*environ)
			*dest = ft_strdup(*environ);
		dest++;
	}
	return (tmp);
}
