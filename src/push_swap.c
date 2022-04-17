/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:16:05 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/15 23:32:45 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack)
{
	int	low;
	int	rotation;

	while (!is_sorted(stack->a))
	{
		if (stack->a->next->value < stack->a->value)
			run_operation("sa", stack);
		rotation = locate_low_num_pos(stack->a, &low);
		while (stack->a->value != low)
		{
			if (rotation == 0)
				run_operation("ra", stack);
			else
				run_operation("rra", stack);
		}
		if (!is_sorted(stack->a))
			run_operation("pb", stack);
	}
	while (stack->b != NULL)
		run_operation("pa", stack);
}

static void	sort_back_to_a(t_stack *stack)
{
	int	high;
	int	rotation;

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

void	long_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->a != NULL)
	{
		if (stack->a->index < i + stack->factor_to_push)
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
	sort_back_to_a(stack);
}

void	create_stack(int argc, char **argv, t_stack *stack)
{
	int		i;

	i = 1;
	stack->a = NULL;
	stack->b = NULL;
	stack->factor_to_push = argc / 200 * 5 + 10;
	while (i < argc)
	{
		insert_back(&stack->a, ft_atoi(argv[i]), -1);
		i++;
	}
	fill_index(&stack->a);
}

int	main(int argc, char **argv)
{	
	t_stack	stack;

	if (argc < 2)
		return (1);
	valid_args(argc, argv);
	create_stack(argc, argv, &stack);
	if (argc - 1 <= 10)
		small_sort(&stack);
	else
		long_sort(&stack);
	free_node(stack.a);
	free_node(stack.b);
	return (0);
}
