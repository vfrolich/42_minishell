/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/24 21:28:49 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	t_list	*lst;
	char	*line;
	t_cmd	**tab;

	if (argc > 2)
	{
		if (!ft_strcmp(argv[1], "AH"))
			exit(1);
	}
	lst = get_env(environ);
	while (42)
	{
		put_prompt(lst);
		get_next_line(0, &line);
		if (!ft_strcmp(line, "exit"))
		{
			free_env(lst);
			ft_strdel(&line);
			exit(0);
		}
		read_entry(line, lst);
		ft_strdel(&line);
	}
	return (0);
}
