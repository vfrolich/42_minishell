/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:47:45 by vfrolich          #+#    #+#             */
/*   Updated: 2017/06/21 15:01:50 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		env_init_2(char *arg, t_list **env)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = 0;
	buff = get_cdir(env);
	buff = ft_strjoin_free_one(&buff, "/");
	tmp = ft_str_epur(arg);
	tmp = ft_strjoin_free(&buff, &tmp);
	set_env("_", tmp, env);
	ft_strdel(&tmp);
}
