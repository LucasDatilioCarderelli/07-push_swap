/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 21:44:07 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/11 03:33:52 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/printf/ft_printf.h"

# define INT_MAX (+2147483647)
# define INT_MIN (-2147483648)

typedef enum e_bool
{
	TRUE	=	1,
	FALSE	=	0
}	t_bool;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		factor_to_push;
}	t_stack;

int			valid_args(int argc, char **argv);
int			is_sorted(t_node *head);

void		insert_back(t_node **head, int value, int index);
void		insert_front(t_node	**head, int value, int index);
void		free_node(t_node *head);
void		print_node(t_node *head);

void		push(t_node **dest, t_node **src);
void		rotate(t_node **head);
void		rrotate(t_node **head);
void		swap(t_node **head);

void		fill_index(t_node **head);
int			locate_high_num_pos(t_node *head, int *high);
int			locate_low_num_pos(t_node *head, int *low);

void		run_operation(char *action, t_stack *stack);

long int	ft_atol(const char *str);

#endif
