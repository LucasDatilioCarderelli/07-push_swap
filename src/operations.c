/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:48:18 by ldatilio          #+#    #+#             */
/*   Updated: 2022/04/11 03:29:56 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
}

void	double_rotate(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
}

void	double_rrotate(t_stack *stack)
{
	rrotate(&stack->a);
	rrotate(&stack->b);
}

void	run_operation(char *action, t_stack *stack)
{
	if (!ft_strncmp(action, "sa", 2))
		swap(&stack->a);
	else if (!ft_strncmp(action, "sb", 2))
		swap(&stack->b);
	else if (!ft_strncmp(action, "pa", 2))
		push(&stack->a, &stack->b);
	else if (!ft_strncmp(action, "pb", 2))
		push(&stack->b, &stack->a);
	else if (!ft_strncmp(action, "ra", 2))
		rotate(&stack->a);
	else if (!ft_strncmp(action, "rb", 2))
		rotate(&stack->b);
	else if (!ft_strncmp(action, "rra", 3))
		rrotate(&stack->a);
	else if (!ft_strncmp(action, "rrb", 3))
		rrotate(&stack->b);
	else if (!ft_strncmp(action, "ss", 2))
		double_swap(stack);
	else if (!ft_strncmp(action, "rr", 2))
		double_rotate(stack);
	else if (!ft_strncmp(action, "rrr", 3))
		double_rrotate(stack);
	ft_printf("%s\n", action);
}
