/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:06:13 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/15 19:27:07 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_usage_setenv(char *str)
{
	ft_putstr_fd("minishell: setenv: \"", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("\": not a valid identifier", 2);
}
