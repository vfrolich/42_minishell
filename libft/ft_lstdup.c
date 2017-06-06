/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 22:45:14 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/06 22:47:21 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*tmp;
	t_list	*start;

	tmp = ft_lstnew(lst->content, ft_strlen(lst->content));
	start = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(lst->content, ft_strlen(lst->content));
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}