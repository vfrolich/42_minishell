/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/21 14:58:47 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*tmp;
	t_list	*start;
	t_env	*envtmp;

	if (!lst)
		return (NULL);
	envtmp = envvar_init(((t_env *)lst->content)->field,
		((t_env *)lst->content)->value);
	tmp = ft_lstnew(envtmp, sizeof(t_env));
	free(envtmp);
	lst = lst->next;
	start = tmp;
	while (lst)
	{
		envtmp = envvar_init(((t_env *)lst->content)->field,
		((t_env *)lst->content)->value);
		tmp->next = ft_lstnew(envtmp, sizeof(t_env));
		free(envtmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}

void	minishell(t_list *env, int ret, char *line)
{
	char	**args;
	int		i;

	while (42)
	{
		pwd_checker(env);
		put_prompt(env);
		get_next_line(0, &line);
		args = ft_strsplit(line, ';');
		i = 0;
		while (args[i])
		{
			ret = read_entry(args[i], &env, ret);
			i++;
		}
		free_tab(args);
		ft_strdel(&line);
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	*line;
	t_list	*env;
	int		ret;

	if (argc > 1)
	{
		ft_putstr_fd("minishell: usage : ", 2);
		ft_putendl_fd(argv[0], 2);
		exit(1);
	}
	ret = 0;
	line = NULL;
	signal(SIGINT, SIG_IGN);
	env = env_init(environ);
	env_init_2(*argv, &env);
	minishell(env, ret, line);
	return (0);
}
