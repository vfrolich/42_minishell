/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 22:50:59 by valentinfrolich   #+#    #+#             */
/*   Updated: 2017/05/22 17:30:06 by vfrolich         ###   ########.fr       */
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

char	**lst_to_tab(t_list *env)
{
	char	**dest;
	size_t	len;
	t_list	*tmp;

	tmp = env;
	len = ft_count_lst(tmp);
	if (!(dest = (char **)malloc(sizeof(char *) * (len + 1))))
	{
		ft_putstr_fd("malloc of char ** dest has failed", 2);
		return (NULL);
	}
	dest[len] = NULL;
	len = 0;
	while (env)
	{
		dest[len] = ft_strjoin(FIELD, "=");
		dest[len] = ft_strjoin_free_one(&dest[len], VALUE);
		len++;
		env = env->next;
	}
	return (&dest[0]);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
}
