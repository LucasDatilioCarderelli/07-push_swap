# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 17:17:45 by ldatilio          #+#    #+#              #
#    Updated: 2021/10/13 22:54:18 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a

CC		:=	gcc
FLAGS	:=	-Wall -Wextra -Werror
RM		:=	rm -f

SRCS	:=	ft_printf.c	ft_types.c libft.c
OBJS	:=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re
