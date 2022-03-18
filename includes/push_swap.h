/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:44:07 by ldatilio          #+#    #+#             */
/*   Updated: 2022/03/17 18:04:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"

typedef enum e_bool
{
	TRUE	=	1,
	FALSE	=	0
}	t_bool;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int		valid_args(int argc, char **argv);

void	insert_back(t_node **head, int value);
void	insert_front(t_node	**head, int value);
void	free_node(t_node *head);
void	print_node(t_node *head);

void	push(t_node **dest, t_node **src);
void	rotate(t_node **head);
void	rrotate(t_node **head);
void	swap(t_node **head);

#endif
