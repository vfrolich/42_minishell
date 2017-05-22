/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/22 17:28:51 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	int		a;
	t_list	*lst;
	char	*line;
	char	*tmp;
	char	**env;

	a = argc;
	env = env_cpy(environ);
	line = ft_strnew(1024);
	lst = get_env(env);
	tmp = search_in_paths(lst, argv[1]);
	if (tmp)
		ft_putendl(tmp);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		if (!ft_strcmp(line, "exit"))
			exit(0);
	}
	return (0);
}
