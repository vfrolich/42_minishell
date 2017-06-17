/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:59:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/17 02:05:22 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cdir(t_list *env)
{
	char	*cdir;
	char	*old;

	cdir = NULL;
	cdir = getcwd(cdir, 256);
	if (!cdir)
	{
		if ((old = get_env_value(env, "OLDPWD")))
			return (old);
		if ((old = get_env_value(env, "HOME")))
			return (old);
		ft_putendl_fd("minishell: neither OLDPWD nor OLDPWD are set", 2);
		exit(1);
	}
	return (cdir);
}

t_env	*envvar_init(char *field, char *value)
{
	t_env	*new;

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

t_list	*set_envvar(char *field, char *value)
{
	t_list	*new;
	t_env	*envvar;

	envvar = envvar_init(field, value);
	new = ft_lstnew(envvar, sizeof(t_env));
	free(envvar);
	return (new);
}
t_list	*env_ex_nihilo(void)
{
	t_list	*lst;
	t_list	*new;
	char	*tmp;
	char	*tmp2;

	tmp = get_cdir(NULL);
	lst = set_envvar("PWD", tmp);
	new = set_envvar("SHLVL", "1");
	lst_add(new, &lst);
	tmp2 = ft_strsub(tmp, 0, ft_strlen(tmp));
	ft_strdel(&tmp);
	tmp = ft_strjoin_free_one(&tmp2, "/minishell");
	new = set_envvar("_", tmp);
	lst_add(new, &lst);
	return (lst);
}

t_list	*env_init(char **env)
{
	t_list	*envi;
	int		shlvl;
	char	*buff;

	if (!*env)
		return (env_ex_nihilo());
	envi = get_env(env);
	unset_env("OLDPWD", envi);
	unset_env("EDITOR", envi);
	set_env("SHELL", "minishell", &envi);
	buff = get_env_value(envi, "SHLVL");
	shlvl = ft_atoi(buff);
	ft_strdel(&buff);
	buff = get_cdir(envi);
	set_env("_", ft_strjoin(ft_strncpy(buff, buff ,ft_strlen(buff) - 1), "/minishell"), &envi);
	ft_strdel(&buff);
	shlvl++;
	buff = ft_itoa(shlvl);
	set_env("SHLVL", buff, &envi);
	ft_strdel(&buff);
	return (envi);
}
