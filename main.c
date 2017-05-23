/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/23 18:58:35 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	t_list	*lst;
	char	*line;

	if (argc > 2)
	{
		if (!ft_strcmp(argv[1], "AH"))
			exit(1);
	}
	lst = get_env(environ);
	while (42)
	{
		put_prompt();
		line = ft_strnew(0);
		get_next_line(0, &line);
		read_entry(line, lst);
		if (!ft_strcmp(line, "exit"))
		{
			free_env(lst);
			ft_strdel(&line);
			exit(0);
		}
		ft_strdel(&line);
	}
	return (0);
}
