/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/02 17:08:37 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	t_list	*lst;
	char	*line;

	if (argc > 1)
	{
		ft_putstr_fd("minishell: usage : ", 2);
		ft_putendl_fd(argv[0], 2);
		exit(1);
	}
	lst = env_init(environ);
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		put_prompt(lst);
		get_next_line(0, &line);
		read_entry(line, lst);
		ft_strdel(&line);
	}
	return (0);
}
