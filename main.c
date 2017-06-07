/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/07 17:59:58 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*tmp;
	t_list	*start;
	t_env	*envtmp;

	envtmp = envvar_init(((t_env *)lst->content)->field,
		((t_env *)lst->content)->value);
	tmp = ft_lstnew(envtmp, sizeof(t_env));
	lst = lst->next;
	start = tmp;
	while (lst)
	{
		envtmp = envvar_init(((t_env *)lst->content)->field,
		((t_env *)lst->content)->value);
		tmp->next = ft_lstnew(envtmp, sizeof(t_env));
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}

void	minishell(char **environ, int ret, char *line)
{
	t_list	*lst;
	char	**args;
	int		i;

	lst = env_init(environ);
	while (42)
	{
		put_prompt(lst);
		get_next_line(0, &line);
		args = ft_strsplit(line, ';');
		i = 0;
		while (args[i])
		{
			ret = read_entry(args[i], lst, ret);
			i++;
		}
		free_tab(args);
		ft_strdel(&line);
	}
}

int		main(int argc, char **argv, char **environ)
{
	char	*line;
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
	minishell(environ, ret, line);
	return (0);
}
