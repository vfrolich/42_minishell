# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfrolich <vfrolich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 16:36:01 by vfrolich          #+#    #+#              #
#    Updated: 2017/05/24 15:42:40 by vfrolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	minishell
FLAGS           =	-Wall -Wextra -Werror
LIB_PATH		=	libft
LIB				=   $(LIB_PATH)/libft.a
LIB_LINK		=	-Llibft -lft
SRC				=	main.c env.c tools.c arg_handle.c prompt.c process.c\
					leaks_handle.c builtins.c

HEADER			=	minishell.h
OBJS			=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) -c $(SRC)
	@$(CC) $(OBJS) $(LIB_LINK) -o $(NAME)

clean :
	@rm -f $(OBJS)
	@make -C $(LIB_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re : fclean all