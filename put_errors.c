/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:06:13 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/08 18:31:45 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_usage_setenv(void)
{
	ft_putstr_fd("setenv: usage : ", 2);
	ft_putendl_fd("setenv [field] [value]", 2);
}
