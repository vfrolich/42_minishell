/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:36:36 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/18 15:57:48 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	int		a;
	t_list	*lst;

	a = argc;
	argv++;
	lst = get_env(environ);
	print_env(lst);
	ft_putchar('\n');
	ft_putendl("---------------------------------------------\n");
	set_env("USER", "adenis", 1, lst);
	print_env(lst);
	ft_putchar('\n');
	ft_putendl("---------------------------------------------\n");
	unset_env("USER", lst);
	print_env(lst);
	return (0);
}
