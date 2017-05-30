/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:59:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/30 15:59:49 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cdir()
{
	char	*cdir;

	cdir = NULL;
	cdir = getcwd(cdir, 256);
	if (!cdir)
	{
		ft_putendl_fd("malloc of char * has failed", 2);
		exit(1);
	}
	return (cdir);
}

t_env	*envvar_init(char *field, char *value)
{
	t_env 	*new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
	{
		ft_putendl_fd("minishell: malloc of t_env * has failed", 2);
		exit(1);
	}
	if (!(new->field = ft_strdup(field)))
	{
		ft_putendl_fd("minishell: malloc of env.field(char *) has failed", 2);
		exit(1);
	}
	if (!(new->value = ft_strdup(value)))
	{
		ft_putendl_fd("minishell: malloc of env.field(char *) has failed", 2);
		exit(1);
	}
	return (new);
}

t_list 	*env_ex_nihilo()
{
	t_list 	*lst;
	t_list	*new;
	t_env	*envvar;
	char	*tmp;

	tmp = get_cdir();
	envvar = envvar_init("PWD", tmp);
	lst = ft_lstnew(envvar, sizeof(t_env));
	free_envvar(envvar);
	envvar = envvar_init("SHLVL", "1");
	new = ft_lstnew(envvar, sizeof(t_env));
	free_envvar(envvar);
	lst_add(new, &lst);
	envvar = envvar_init("_", ft_strjoin(tmp, "./minishell"));
	ft_strdel(&tmp);
	new = ft_lstnew(envvar, sizeof(t_env));
	free_envvar(envvar);
	lst_add(new, &lst);
	return (lst);
}

t_list	*env_init(char **env)
{
	t_list	*envi;
	int		tmp;
	char	*tmp2;

	if (!*env)
		return (env_ex_nihilo());
	envi = get_env(env);
	tmp = ft_atoi(get_env_value(envi, "SHLVL"));
	tmp++;
	tmp2 = ft_itoa(tmp);
	set_env("SHLVL", tmp2, 1, envi);
	ft_strdel(&tmp2);
	return (envi);	
}