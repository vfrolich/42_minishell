/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentinfrolich <valentinfrolich@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/19 00:26:23 by valentinfrolich  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	int		a;
	t_list	*lst;
	char	*line;
	char	**env;

	a = argc;
	argv++;
	env = env_cpy(environ);
	line = ft_strnew(1024);
	lst = get_env(env);
	env = lst_to_tab(lst);
	ft_putendl(*env);
	while (*env)
	{
		ft_putendl(*env);
		env++;
	}
	// while (42)
	// {
	// 	ft_putstr("$> ");
	// 	get_next_line(0, &line);
	// 	if (!ft_strcmp(line, "exit"))
	// 		exit(0);
	// }
	return (0);
}
