/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:59:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/02 19:32:18 by vfrolich         ###   ########.fr       */
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

t_list	*env_ex_nihilo(void)
{
	t_list	*lst;
	t_list	*new;
	t_env	*envvar;
	char	*tmp;

	tmp = get_cdir(NULL);
	envvar = envvar_init("PWD", tmp);
	lst = ft_lstnew(envvar, sizeof(t_env));
	free(envvar);
	envvar = envvar_init("SHLVL", "1");
	new = ft_lstnew(envvar, sizeof(t_env));
	free(envvar);
	lst_add(new, &lst);
	tmp = ft_strjoin_free_one(&tmp, "./minishell");
	envvar = envvar_init("_", tmp);
	ft_strdel(&tmp);
	new = ft_lstnew(envvar, sizeof(t_env));
	free(envvar);
	lst_add(new, &lst);
	return (lst);
}

t_list	*env_init(char **env)
{
	t_list	*envi;
	int		tmp;
	char	*tmp2;

	if (!*env)
	{
		envi = env_ex_nihilo();
		return (envi);
	}
	envi = get_env(env);
	unset_env("OLDPWD", envi);
	tmp2 = get_env_value(envi, "SHLVL");
	tmp = ft_atoi(tmp2);
	ft_strdel(&tmp2);
	tmp++;
	tmp2 = ft_itoa(tmp);
	set_env("SHLVL", tmp2, envi);
	ft_strdel(&tmp2);
	return (envi);
}
