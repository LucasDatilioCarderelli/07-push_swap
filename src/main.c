/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/10 21:38:11 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack)
{
	int	low;
	int	rotation;

	while (!is_sorted(stack -> a))
	{
		if (stack -> a -> next -> value < stack -> a -> value)
			run_operation("sa", stack);
		rotation = locate_low_num_pos(stack -> a, &low);
		while (stack -> a -> value != low)
		{
			if (rotation == 0)
				run_operation("ra", stack);
			else
				run_operation("rra", stack);
		}
		if (!is_sorted(stack -> a))
			run_operation("pb", stack);
	}
	while (stack -> b != NULL)
		run_operation("pa", stack);
}

void	long_sort(t_stack *stack)
{
	int	i;
	int	high;
	int	rotation;

	locate_low_num_pos(stack->a, &i);
	while (stack->a != NULL)
	{
		if (stack->a->value < i + stack->factor_to_push)
		{
			run_operation("pb", stack);
			i++;
		}
		else
		{
			if (stack->b && stack->b->next && \
				stack->b->value < stack->b->next->value)
				run_operation("rr", stack);
			else
				run_operation("ra", stack);
		}
	}
	while (stack->b != NULL)
	{
		rotation = locate_high_num_pos(stack->b, &high);
		while (stack->b->value != high)
		{
			if (rotation == 0)
				run_operation("rb", stack);
			else
				run_operation("rrb", stack);
		}
		run_operation("pa", stack);
	}
}

void	create_stack(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;
	stack.factor_to_push = argc / 200 * 5 + 10;
	while (i < argc)
	{
		insert_back(&stack.a, ft_atoi(argv[i]));
		i++;
	}
	if (argc - 1 <= 10)
		small_sort(&stack);
	else
		long_sort(&stack);
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
