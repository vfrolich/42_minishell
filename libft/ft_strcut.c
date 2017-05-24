/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:12:37 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/24 19:55:37 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char c)
{
	size_t	diff;
	char	*tmp;
	int		i;

	tmp = str;
	diff = 0;
	while (*tmp)
	{
		if (*tmp == c)
			diff++;
		tmp++;
	}
	diff = ft_strlen(str) - diff;
	tmp = ft_strnew(diff);
	diff = 0;
	i = 0;
	while (str[diff])
	{
		if (str[diff] != c)
		{
			tmp[i] = str[diff];
			i++;
		}
		str++;
	}
	return (tmp);
}