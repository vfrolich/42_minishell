/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:39:08 by vfrolich          #+#    #+#             */
/*   Updated: 2017/05/18 15:54:12 by vfrolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_env{

	char		*field;
	char		*value;
}				t_env;

void			free_env(t_list *env);
void			print_env(t_list *env);
t_env			*get_fields(char *env);
t_list			*get_env(char **env);
int				add_env(char *name, char *value, t_list *lst);
int				set_env(char *name, char *value, int overwrite, t_list *env);
int				unset_env(char	*name, t_list *env);

#endif
