/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentinfrolich <valentinfrolich@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 22:51:53 by valentinfrolich   #+#    #+#             */
/*   Updated: 2017/05/18 23:44:02 by valentinfrolich  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_lst(t_list	*lst)
{
	size_t	size;
	t_list	*start;

	start = lst;
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	lst = start;
	return (size);
}
