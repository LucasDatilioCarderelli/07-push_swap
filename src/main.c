/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/01 03:24:04 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operations(char *action, t_stack *stack)
{
	if (!ft_strncmp(action, "sa", 2))
		swap(&stack -> a);
	else if (!ft_strncmp(action, "sb", 2))
		swap(&stack -> b);
	else if (!ft_strncmp(action, "pa", 2))
		push(&stack -> a, &stack -> b);
	else if (!ft_strncmp(action, "pb", 2))
		push(&stack -> b, &stack -> a);
	else if (!ft_strncmp(action, "ra", 2))
		rotate(&stack -> a);
	else if (!ft_strncmp(action, "rb", 2))
		rotate(&stack -> b);
	else if (!ft_strncmp(action, "rra", 3))
		rrotate(&stack -> a);
	else if (!ft_strncmp(action, "rrb", 3))
		rrotate(&stack -> b);
	ft_printf("%s\n", action);
}

int	low_num_pos(t_node *head, int *low)
{
	int	low_pos;
	int	i;

	*low = head -> value;
	while (head)
	{
		if (head -> value < *low)
		{
			*low = head -> value;
			low_pos = i;
		}
		head = head -> next;
		i++;
	}
	if (low_pos > i / 2)
		return (1);
	return (0);
}

void	sort(t_stack *stack)
{
	int	low;
	int	rotation;

	while (!is_sorted(stack -> a))
	{
		if (stack -> a -> next -> value < stack -> a -> value)
			operations("sa", stack);
		rotation = low_num_pos(stack -> a, &low);
		while (stack -> a -> value != low)
		{
			if (rotation == 0)
				operations("ra", stack);
			else
				operations("rra", stack);
		}
		if (!is_sorted(stack -> a))
			operations("pb", stack);
	}
	while (stack -> b != NULL)
		operations("pa", stack);
}

void	create_stack(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;
	while (i < argc)
	{
		insert_back(&stack.a, ft_atoi(argv[i]));
		i++;
	}
	sort(&stack);
	free_node(stack.a);
	free_node(stack.b);
}

int	main(int argc, char **argv)
{	
	if (argc < 3)
		return (1);
	valid_args(argc, argv);
	create_stack(argc, argv);
	return (0);
}
