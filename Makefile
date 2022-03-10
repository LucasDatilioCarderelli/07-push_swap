# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 15:13:58 by ldatilio          #+#    #+#              #
#    Updated: 2022/03/10 23:03:52 by ldatilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
HEADER		=	push_swap.h

INCLUDE		=	-I ./includes

CC			=	gcc -g
RM			=	rm -f
CFLAG		=	-Wall -Wextra -Werror -fsanitize=leak

LIBFT		=	./libs/libft/libft.a

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/

SRC_FILES	=	main.c	\

SRC			=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_FILES)))

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
				
$(LIBFT):
				make bonus -C ./libs/libft

clean:
				$(RM) $(OBJ)
				make clean -C libs/libft

fclean:			clean
				$(RM) $(NAME)

fclean_libs:	fclean
				make fclean -C libs/libft

re:
				fclean all

.PHONY:			all, clean, fclean, re